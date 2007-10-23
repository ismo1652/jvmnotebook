--
-- Berlin Brown
--
-- updated: 11/12/2006
--
-- connect to the
-- databatase
--
-- file: create_tables.sql
-- see insert_tables.sql

connect botlist_development;

CREATE TABLE user_links (
  id 				int(11) NOT NULL auto_increment,
  main_url			varchar(255) NOT NULL,
  url_title			varchar(128),
  url_description 	varchar(255),
  keywords			varchar(255),
  source			varchar(40),
  source_url		varchar(255),
  total_rating		int(11) DEFAULT 0,
  occurrence		int(11) DEFAULT 0,
  created_on		DATETIME NOT NULL DEFAULT '0000-00-00 00:00:00',
  PRIMARY KEY (id)
);

--
-- Keep a user log
CREATE TABLE user_visit_log (
	id 			int(11) NOT NULL auto_increment,	
	remote_host	varchar(30),
	host 		varchar(30),
	referer		varchar(255),
	user_agent	varchar(255),
	request_uri	varchar(255),
	request_page varchar(124),	
	created_on  DATETIME NOT NULL DEFAULT '0000-00-00 00:00:00',
	PRIMARY KEY (id)
);


--
-- City listings
CREATE TABLE city_listing (
	id 				int(11) NOT NULL auto_increment,
	city_name		varchar(255) NOT NULL UNIQUE,
	created_on		DATETIME NOT NULL DEFAULT '0000-00-00 00:00:00',
  	PRIMARY KEY (id)
);

--
-- Create a default post ad listing
-- A post listing has a city
CREATE TABLE post_listing (
  id 				int(11) NOT NULL auto_increment,
  city_id			int(11) NOT NULL,
  category			varchar(128) NOT NULL,
  email				varchar(128) NOT NULL,  
  location			varchar(255),
  title				varchar(255) NOT NULL,
  main_url			varchar(255),
  keywords			varchar(255),
  message 			text NOT NULL,
  age				int(11) DEFAULT 0,
  created_on		DATETIME NOT NULL DEFAULT '0000-00-00 00:00:00',  
  PRIMARY KEY (id),
  constraint fk_post_listing
			foreign key (city_id) references city_listing(id)
);

--
-- Create the user admin tables for 
CREATE TABLE users (
	username VARCHAR(50) NOT NULL PRIMARY KEY,
	password VARCHAR(50) NOT NULL,
	enabled BIT NOT NULL
);

CREATE TABLE authorities (
	username VARCHAR(50) NOT NULL,
	authority VARCHAR(50) NOT NULL
);

ALTER TABLE authorities ADD CONSTRAINT fk_authorities_users foreign key (username) REFERENCES users(username);

-- End of file