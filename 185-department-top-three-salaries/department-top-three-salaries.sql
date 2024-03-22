select Department, Employee, Salary
from ( 
select d.name as Department, e.name as Employee, e.salary as Salary, dense_rank() over(
                       partition by d.name 
                       order by salary desc 
                       ) new 
from employee e
join department d 
on e.departmentId = d.id
) tab
where new <= 3