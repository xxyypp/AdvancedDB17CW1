/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

IF OBJECT_ID('review_user_fk', 'F') IS NOT NULL
  ALTER TABLE [review]
    DROP CONSTRAINT [review_user_fk];
GO

IF OBJECT_ID('user', 'U') IS NOT NULL
  DROP TABLE [user];
GO

IF OBJECT_ID('review', 'U') IS NOT NULL
  DROP TABLE [review];
GO

CREATE TABLE [review] (
  [id] INT NOT NULL PRIMARY KEY,
  [business_id] INT NOT NULL,
  [user_id] INT NOT NULL,
  [user] VARCHAR(22) NOT NULL);
GO

CREATE TABLE [user] (
  [id] VARCHAR(22) NOT NULL PRIMARY KEY);
GO

/*
ALTER TABLE [review]
  ADD CONSTRAINT [review_user_fk]
    FOREIGN KEY ([user])
    REFERENCES [user] ([id])
*/

