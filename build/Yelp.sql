/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

IF OBJECT_ID('review_business_id_fk', 'F') IS NOT NULL
  ALTER TABLE [review]
    DROP CONSTRAINT [review_business_id_fk];
GO

IF OBJECT_ID('hours', 'U') IS NOT NULL
  DROP TABLE [hours];
GO

IF OBJECT_ID('business', 'U') IS NOT NULL
  DROP TABLE [business];
GO

IF OBJECT_ID('review', 'U') IS NOT NULL
  DROP TABLE [review];
GO

IF OBJECT_ID('user', 'U') IS NOT NULL
  DROP TABLE [user];
GO

CREATE TABLE [user] (
  [id] VARCHAR(256) NOT NULL PRIMARY KEY,
  [name] VARCHAR(512) NOT NULL);
GO

CREATE TABLE [review] (
  [id] VARCHAR(256) NOT NULL PRIMARY KEY,
  [user_id] VARCHAR(256) NOT NULL,
  [business_id] VARCHAR(256) NOT NULL
  /*
  CONSTRAINT [review_user_id_fk]
    FOREIGN KEY ([user_id])
    REFERENCES [user] ([id])
  */);
GO

CREATE TABLE [business] (
  [id] VARCHAR(256) NOT NULL PRIMARY KEY);
GO

CREATE TABLE [hours] (
  [id] INT NOT NULL PRIMARY KEY,
  [hours] VARCHAR(512) NOT NULL,
  [business_id] VARCHAR(256) NOT NULL
  /*
  CONSTRAINT [hours_business_id_fk]
    FOREIGN KEY ([business_id])
    REFERENCES [business] ([id])
  */);
GO

/*
ALTER TABLE [review]
  ADD CONSTRAINT [review_business_id_fk]
    FOREIGN KEY ([business_id])
    REFERENCES [business] ([id])
*/

