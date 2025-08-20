const fs = require('fs');
const path = require('path');

const hexmapPath = path.join(__dirname, 'hexmap.csv');
const stagesPath = path.join(__dirname, 'stages.csv');

async function addSeedsToStages(repeatCount = 5) { // 몇 개 생성할지 매개변수로 받음
    try {
        // 1. hexmap.csv 읽기
        const hexmapContent = await fs.promises.readFile(hexmapPath, 'utf8');
        const hexmapSeeds = hexmapContent.trim().split('\n').filter(line => line.length > 0);

        if (hexmapSeeds.length < 3) {
            console.error('hexmap.csv must contain at least 3 seeds.');
            return;
        }

        // 2. stages.csv 읽기 또는 초기화
        let stagesContent = '';
        let currentIndex = 0;
        try {
            stagesContent = await fs.promises.readFile(stagesPath, 'utf8');
            const lines = stagesContent.trim().split('\n');
            if (lines.length > 0) {
                const lastLine = lines[lines.length - 1];
                const lastIndexMatch = lastLine.match(/^(\d+),/);
                if (lastIndexMatch) {
                    currentIndex = parseInt(lastIndexMatch[1], 10) + 1;
                }
            }
        } catch (error) {
            if (error.code === 'ENOENT') {
                stagesContent = 'index,seed1,seed2,seed3'; // 헤더 추가
            } else {
                throw error;
            }
        }

        // 3. 반복해서 여러 줄 추가
        let newEntries = '';
        for (let i = 0; i < repeatCount; i++) {
            // 3-1. 랜덤 시드 3개 뽑기
            const randomIndexes = [];
            while (randomIndexes.length < 3) {
                const randomIndex = Math.floor(Math.random() * hexmapSeeds.length);
                if (!randomIndexes.includes(randomIndex)) {
                    randomIndexes.push(randomIndex);
                }
            }
            const selectedSeeds = randomIndexes.map(index => hexmapSeeds[index]);

            // 3-2. 새로운 엔트리 생성
            const newEntry = `\n${currentIndex + i},${selectedSeeds[0]},${selectedSeeds[1]},${selectedSeeds[2]}`;
            newEntries += newEntry;
        }

        // 4. 파일에 이어붙이기
        stagesContent += newEntries;
        await fs.promises.writeFile(stagesPath, stagesContent, 'utf8');

        console.log(`${repeatCount}개의 스테이지가 stages.csv에 추가됨`);
    } catch (error) {
        console.error('Error:', error);
    }
}

addSeedsToStages(10); // 10개 생성
