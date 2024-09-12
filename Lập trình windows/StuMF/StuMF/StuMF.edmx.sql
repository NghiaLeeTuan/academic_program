
-- --------------------------------------------------
-- Entity Designer DDL Script for SQL Server 2005, 2008, 2012 and Azure
-- --------------------------------------------------
-- Date Created: 04/09/2022 19:19:16
-- Generated from EDMX file: D:\Môn học\Lập trình windows\StuMF\StuMF\StuMF.edmx
-- --------------------------------------------------

SET QUOTED_IDENTIFIER OFF;
GO
USE [STudentMF];
GO
IF SCHEMA_ID(N'dbo') IS NULL EXECUTE(N'CREATE SCHEMA [dbo]');
GO

-- --------------------------------------------------
-- Dropping existing FOREIGN KEY constraints
-- --------------------------------------------------


-- --------------------------------------------------
-- Dropping existing tables
-- --------------------------------------------------


-- --------------------------------------------------
-- Creating all tables
-- --------------------------------------------------

-- Creating table 'StuSet'
CREATE TABLE [dbo].[StuSet] (
    [Id] int IDENTITY(1,1) NOT NULL,
    [Name] nvarchar(max)  NOT NULL
);
GO

-- Creating table 'DepartmentSet'
CREATE TABLE [dbo].[DepartmentSet] (
    [Id] int IDENTITY(1,1) NOT NULL,
    [Name] nvarchar(max)  NOT NULL,
    [StuId] int  NOT NULL
);
GO

-- --------------------------------------------------
-- Creating all PRIMARY KEY constraints
-- --------------------------------------------------

-- Creating primary key on [Id] in table 'StuSet'
ALTER TABLE [dbo].[StuSet]
ADD CONSTRAINT [PK_StuSet]
    PRIMARY KEY CLUSTERED ([Id] ASC);
GO

-- Creating primary key on [Id] in table 'DepartmentSet'
ALTER TABLE [dbo].[DepartmentSet]
ADD CONSTRAINT [PK_DepartmentSet]
    PRIMARY KEY CLUSTERED ([Id] ASC);
GO

-- --------------------------------------------------
-- Creating all FOREIGN KEY constraints
-- --------------------------------------------------

-- Creating foreign key on [StuId] in table 'DepartmentSet'
ALTER TABLE [dbo].[DepartmentSet]
ADD CONSTRAINT [FK_StuDepartment]
    FOREIGN KEY ([StuId])
    REFERENCES [dbo].[StuSet]
        ([Id])
    ON DELETE NO ACTION ON UPDATE NO ACTION;
GO

-- Creating non-clustered index for FOREIGN KEY 'FK_StuDepartment'
CREATE INDEX [IX_FK_StuDepartment]
ON [dbo].[DepartmentSet]
    ([StuId]);
GO

-- --------------------------------------------------
-- Script has ended
-- --------------------------------------------------