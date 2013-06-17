drop database live_capture;
create database live_capture;

use live_capture;
create table packets_details (
	id int auto_increment primary key,
	caplen int,
	len int,
	timestamp datetime,

	data blob,

	src_ip varchar(20),
	dst_ip varchar(20),

	src_port int,
	dst_port int,
	transport_protocol varchar(20),
	
	application_protocol varchar(20),
	
	task_id char(2),
	task_name varchar(50),

	category_id char(2),
	category_name varchar(50)
);
