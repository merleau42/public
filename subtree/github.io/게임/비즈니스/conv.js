const fs = require('fs');
const path = require('path');

// --- 환경 설정 ---
// 변환할 숫자의 현재 진수 (예: 10, 2, 16)
const INPUT_BASE = 16;
// 변환하고 싶은 새로운 진수 (예: 10, 2, 8)
const OUTPUT_BASE = 3;
// 결과가 표시될 최소 자릿수 (0으로 패딩될 길이)
const PAD_LENGTH = 9;
// 입력 파일 경로
const inputFilePath = path.join(__dirname, 'hexmap.csv');
// 출력 파일 경로
const outputFilePath = path.join(__dirname, 'map.csv');

/**
 * 주어진 진수(N)의 숫자를 다른 진수(M)로 변환하고, 특정 길이로 0을 패딩하는 함수입니다.
 * @param {string} number - 변환할 숫자 문자열.
 * @param {number} inputBase - 입력 숫자의 진수.
 * @param {number} outputBase - 출력 숫자의 진수.
 * @param {number} padLength - 결과 문자열의 최소 길이.
 * @returns {string | null} - 변환된 숫자 문자열 또는 유효하지 않은 입력의 경우 null.
 */
function convertBase(number, inputBase, outputBase, padLength) {
    const trimmedNumber = number.trim();
    if (trimmedNumber === '') {
        return null; // 빈 줄은 건너뜁니다.
    }
    
    try {
        // 입력 진수를 사용하여 10진수로 변환합니다.
        const decimalValue = parseInt(trimmedNumber, inputBase);
        
        // parseInt가 NaN을 반환하면 유효하지 않은 입력입니다.
        if (isNaN(decimalValue)) {
            console.error(`Error: Invalid number "${number}" for base ${inputBase}`);
            return null;
        }

        // 10진수 값을 원하는 출력 진수로 변환합니다.
        let converted = decimalValue.toString(outputBase);

        // padLength가 0보다 크면 0으로 패딩을 적용합니다.
        if (padLength > 0) {
            converted = converted.padStart(padLength, '0');
        }

        return converted;
    } catch (e) {
        console.error(`An error occurred while converting "${number}":`, e.message);
        return null;
    }
}

// 파일 변환 프로세스를 실행하는 비동기 함수입니다.
async function processFile() {
    try {
        // 입력 파일을 비동기적으로 읽습니다.
        console.log(`Reading from file: ${inputFilePath}`);
        const fileContent = await fs.promises.readFile(inputFilePath, 'utf8');

        // 줄바꿈으로 내용을 분리하고 각 줄을 처리합니다.
        const lines = fileContent.split(/\r?\n/).filter(line => line.trim() !== '');
        const convertedResults = [];

        console.log(`Converting numbers from base ${INPUT_BASE} to base ${OUTPUT_BASE} with padding...`);
        
        for (const line of lines) {
            const converted = convertBase(line, INPUT_BASE, OUTPUT_BASE, PAD_LENGTH);
            if (converted !== null) {
                // 원본 진수, 변환된 진수, 패딩된 결과를 모두 포함한 문자열을 결과 배열에 추가합니다.
                convertedResults.push(converted);
            }
        }

        const outputContent = convertedResults.join('\n');

        // 변환 결과를 파일에 비동기적으로 씁니다.
        console.log(`Writing results to file: ${outputFilePath}`);
        await fs.promises.writeFile(outputFilePath, outputContent, 'utf8');

        console.log('\n--- Conversion successful! Results ---');
        console.log(outputContent);

    } catch (error) {
        console.error('An error occurred:', error);
    }
}

// 함수를 실행하여 변환 프로세스를 시작합니다.
processFile();
