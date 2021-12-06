CREATE TABLE emp_temp AS
  SELECT employee_id, first_name, last_name 
  FROM employees;
 
CREATE OR REPLACE PROCEDURE test_proc (
  z_emp_id NUMBER
) AUTHID DEFINER AS
BEGIN
  DELETE FROM emp_temp
  WHERE employee_id = z_emp_id;
 
  IF SQL%FOUND THEN
    DBMS_OUTPUT.PUT_LINE (
      'Delete succeeded for employee_id: ' || z_emp_id
    );
  ELSE
    DBMS_OUTPUT.PUT_LINE ('No employee of ID '|| z_emp_id||'is found.');
  END IF;
END;
/
BEGIN
  test_proc(175);
  test_proc(444);
END;
/