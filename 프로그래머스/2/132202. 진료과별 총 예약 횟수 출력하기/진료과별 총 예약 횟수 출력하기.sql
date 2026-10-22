-- 코드를 입력하세요

# APPOINTMENT 테이블에서 2022년 5월에 예약한 환자 수를 진료과코드별로 조회하는 SQL문
# 컬럼명 진료과 코드, 5월 예약건수 로 지정.
# 진료과별 예약한 환자 수를 기준으로 오름차순
# 진료과 코드를 기준으로 오름차순

SELECT MCDP_CD AS '진료과 코드', COUNT(APNT_YMD) AS '5월 예약건수'
FROM APPOINTMENT
WHERE MONTH(APNT_YMD) = 05
GROUP BY MCDP_CD
ORDER BY COUNT(APNT_YMD) ASC, MCDP_CD ASC;