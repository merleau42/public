from bs4 import BeautifulSoup
import os, copy
import re

print("기본 디렉토리:", os.getcwd())
os.chdir('./네비게이터/BOJ')
print("디렉토리 설정:", os.getcwd())

def convert(problem_number):
    input_file_path = f'./input/{problem_number}.html'
    output_file_path = f'./output/{problem_number}.html'

    with open(input_file_path, 'r', encoding='utf-8') as input_file:
        soup = BeautifulSoup(input_file, 'html.parser')
    
    with open(input_file_path, 'r', encoding='utf-8') as input_file:
        soup2 = BeautifulSoup(input_file, 'html.parser')

    img_tags = soup.find_all('img')

    for img_tag in img_tags:
        src = img_tag.get('src')
        if src.startswith('/upload/'):
            img_tag['src'] = f'https://www.acmicpc.net{src}'

    problem_section_tags = soup.select('section .problem-text:not([id*="problem_sample_explain"])')

    for tag in soup2.find_all(['h2','th']):
      tag.decompose()

    foreign = '외국어' if (len(re.findall(r'[가-힣]',str(soup2))) < 10) else '한국어'
    problem_table_html = f'<table class="problem-table"><tr><td class="title-column">정보</td><td align="center">{problem_number}번,{foreign}</td></tr>'

    for section in problem_section_tags:
        title = section.parent.select_one('h2').text if section.parent.select_one('h2') is not None else ''
        content = section.prettify()
        problem_table_html += f'<tr><td class="title-column">{title}</td><td>{content}</td></tr>\n'
    problem_table_html += '</table><br><br>'


    sample_sections = soup.select('section:not(#description, #input, #output, #limit, #subtask, #custom_explain, #custom_files, #custom_funcdef)')
    table_html = "<table><tr><th>입력</th><th>출력</th>" + ("<th>참고</th></tr>" if soup.select_one('[id*=problem_sample_explain]') else "</tr>")

    input_data, output_data, reference_data = "", "", ""
    for index, section in enumerate(sample_sections):
        input_data_element = section.select_one('.sampledata[id*=sample-input]')
        output_data_element = section.select_one('.sampledata[id*=sample-output]')
        reference_data_element = section.select_one('[id*=problem_sample_explain]')

        input_data_element = input_data_element.text.strip() if input_data_element else ""
        output_data_element = output_data_element.text.strip() if output_data_element else ""
        reference_data_element = reference_data_element.prettify() if reference_data_element else ""

        input_data += input_data_element + "\n" if input_data_element else ""
        output_data += output_data_element + "\n" if output_data_element else ""
        reference_data += reference_data_element + "\n" if reference_data_element else ""

        next_section = sample_sections[index + 1] if index + 1 < len(sample_sections) else section
        next_input_data_element = next_section.select_one('.sampledata[id*=sample-input]')

        if next_input_data_element or index + 1 == len(sample_sections):
            table_html += f"<tr><td><pre>{input_data.strip()}</pre></td><td><pre>{output_data.strip()}</pre>"
            table_html += f"</td><td>{reference_data.strip()}</td>" if soup.select_one('[id*=problem_sample_explain]') else ""
            table_html += f"</tr>"
            input_data, output_data, reference_data = "", "", ""
    table_html += '</table>'

    with open(output_file_path, 'w', encoding='utf-8') as output_file:
        output_file.write('<style>.mjx-copytext {font-size: 0;}</style>\n')
        output_file.write('<style>.title-column { width: 45px; text-align: center;}</style>\n')
        output_file.write('<style>table { width: 100%; }</style>\n')
        output_file.write('<style>td { height: 30px; }</style>\n')
        output_file.write('<style>table, th, td { border-collapse: collapse; border: 1px solid black; }</style>\n')
        output_file.write('<style>pre {color:white; font-family:Courier New; padding:5px; line-height:1.36;}</style>\n')
        output_file.write(problem_table_html)
        output_file.write('\n\n')
        output_file.write(table_html)


for file_name in  os.listdir('./input'):
    convert(re.sub(r'\.html$','',file_name))