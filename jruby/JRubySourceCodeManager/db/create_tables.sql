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

-- connect botlist_development;

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
CREATE TABLE user_visit_audit (
	id 			int(11) NOT NULL auto_increment,	
	remote_host	varchar(30),
	party_poll	varchar(3) DEFAULT 'DEM',
	created_on  DATETIME NOT NULL DEFAULT '0000-00-00 00:00:00',
	PRIMARY KEY (id)
);


--
-- Create a default post ad listing
CREATE TABLE post_listing (
  id 				int(11) NOT NULL auto_increment,
  email				varchar(128) NOT NULL,
  location			varchar(255),
  title				varchar(255) NOT NULL,
  message 			text NOT NULL,
  age				int(11) DEFAULT 0,
  created_on		DATETIME NOT NULL DEFAULT '0000-00-00 00:00:00',
  PRIMARY KEY (id)
);


--
-- system_web_files
CREATE TABLE system_web_files (
	id 			int(11) NOT NULL auto_increment,	
	filename	varchar(255) NOT NULL,
	fsize		int(10) NOT NULL,
	fmtime		int(10) NOT NULL,
	fext		varchar(40) NOT NULL,
	projectname	varchar(80) NOT NULL,
	created_on  DATETIME NOT NULL DEFAULT '0000-00-00 00:00:00',
	PRIMARY KEY (id)
);

-- End of file