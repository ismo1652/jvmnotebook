--
-- Berlin Brown
--
--
connect botlist_development;

INSERT INTO city_listing(city_name, created_on) VALUES('Atlanta', NOW());
INSERT INTO city_listing(city_name, created_on) VALUES('Austin', NOW());

INSERT INTO city_listing(city_name, created_on) VALUES('Dallas', NOW());
INSERT INTO city_listing(city_name, created_on) VALUES('Houston', NOW());
INSERT INTO city_listing(city_name, created_on) VALUES('Miami', NOW());
INSERT INTO city_listing(city_name, created_on) VALUES('NewYork', NOW());
INSERT INTO city_listing(city_name, created_on) VALUES('SF', NOW());
INSERT INTO city_listing(city_name, created_on) VALUES('Seattle', NOW());

INSERT INTO city_listing(city_name, created_on) VALUES('Bangalore', NOW());
INSERT INTO city_listing(city_name, created_on) VALUES('Berlin', NOW());
INSERT INTO city_listing(city_name, created_on) VALUES('London', NOW());
INSERT INTO city_listing(city_name, created_on) VALUES('Tokyo', NOW());
INSERT INTO city_listing(city_name, created_on) VALUES('Other', NOW());

-- Insert example users
-- To encode the password, see the ViewMD5Encoding class

INSERT INTO USERS VALUES('berlinbrown','55bbf4f03036d6642f935c6a53795372',TRUE);

INSERT INTO authorities VALUES ('berlinbrown', 'ROLE_TELLER');
INSERT INTO authorities VALUES ('berlinbrown', 'ROLE_SUPERVISOR');
