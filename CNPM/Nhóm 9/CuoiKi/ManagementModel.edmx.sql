
-- --------------------------------------------------
-- Entity Designer DDL Script for SQL Server 2005, 2008, 2012 and Azure
-- --------------------------------------------------
-- Date Created: 06/03/2022 22:43:22
-- Generated from EDMX file: D:\Môn học\Lập trình windows\cuoi_ki-main\CuoiKi\ManagementModel.edmx
-- --------------------------------------------------

SET QUOTED_IDENTIFIER OFF;
GO
USE [Win_Final];
GO
IF SCHEMA_ID(N'dbo') IS NULL EXECUTE(N'CREATE SCHEMA [dbo]');
GO

-- --------------------------------------------------
-- Dropping existing FOREIGN KEY constraints
-- --------------------------------------------------

IF OBJECT_ID(N'[dbo].[FK__Employee__employ__1CF15040]', 'F') IS NOT NULL
    ALTER TABLE [dbo].[Employee] DROP CONSTRAINT [FK__Employee__employ__1CF15040];
GO
IF OBJECT_ID(N'[dbo].[FK__Lineitem__item_i__1FCDBCEB]', 'F') IS NOT NULL
    ALTER TABLE [dbo].[Lineitem] DROP CONSTRAINT [FK__Lineitem__item_i__1FCDBCEB];
GO
IF OBJECT_ID(N'[dbo].[FK__Lineitem__order___1ED998B2]', 'F') IS NOT NULL
    ALTER TABLE [dbo].[Lineitem] DROP CONSTRAINT [FK__Lineitem__order___1ED998B2];
GO
IF OBJECT_ID(N'[dbo].[FK__Orders__customer__1BFD2C07]', 'F') IS NOT NULL
    ALTER TABLE [dbo].[Orders] DROP CONSTRAINT [FK__Orders__customer__1BFD2C07];
GO
IF OBJECT_ID(N'[dbo].[FK__Orders__employee__1DE57479]', 'F') IS NOT NULL
    ALTER TABLE [dbo].[Orders] DROP CONSTRAINT [FK__Orders__employee__1DE57479];
GO

-- --------------------------------------------------
-- Dropping existing tables
-- --------------------------------------------------

IF OBJECT_ID(N'[dbo].[Accounts]', 'U') IS NOT NULL
    DROP TABLE [dbo].[Accounts];
GO
IF OBJECT_ID(N'[dbo].[Customers]', 'U') IS NOT NULL
    DROP TABLE [dbo].[Customers];
GO
IF OBJECT_ID(N'[dbo].[Employee]', 'U') IS NOT NULL
    DROP TABLE [dbo].[Employee];
GO
IF OBJECT_ID(N'[dbo].[Item]', 'U') IS NOT NULL
    DROP TABLE [dbo].[Item];
GO
IF OBJECT_ID(N'[dbo].[Lineitem]', 'U') IS NOT NULL
    DROP TABLE [dbo].[Lineitem];
GO
IF OBJECT_ID(N'[dbo].[Orders]', 'U') IS NOT NULL
    DROP TABLE [dbo].[Orders];
GO
IF OBJECT_ID(N'[dbo].[Voucher]', 'U') IS NOT NULL
    DROP TABLE [dbo].[Voucher];
GO

-- --------------------------------------------------
-- Creating all tables
-- --------------------------------------------------

-- Creating table 'Accounts'
CREATE TABLE [dbo].[Accounts] (
    [Name] nvarchar(50)  NULL,
    [Account1] nvarchar(50)  NOT NULL,
    [Password] nvarchar(50)  NULL,
    [Position] nvarchar(20)  NULL
);
GO

-- Creating table 'Employees'
CREATE TABLE [dbo].[Employees] (
    [employee_id] int IDENTITY(1,1) NOT NULL,
    [employee_account] nvarchar(50)  NULL,
    [employee_name] nvarchar(100)  NULL,
    [phone] nvarchar(15)  NULL,
    [address] nvarchar(30)  NULL,
    [birth] datetime  NULL,
    [shift] nvarchar(20)  NULL,
    [salary] float  NULL
);
GO

-- Creating table 'Items'
CREATE TABLE [dbo].[Items] (
    [item_id] int IDENTITY(1,1) NOT NULL,
    [item_name] nvarchar(100)  NULL,
    [item_price_in] float  NULL,
    [item_price_out] float  NULL,
    [quantity_in_stock] int  NULL,
    [expiry] datetime  NULL
);
GO

-- Creating table 'Lineitems'
CREATE TABLE [dbo].[Lineitems] (
    [order_id] int  NOT NULL,
    [item_id] int  NOT NULL,
    [quantity] int  NULL
);
GO

-- Creating table 'Orders'
CREATE TABLE [dbo].[Orders] (
    [order_id] int IDENTITY(1,1) NOT NULL,
    [order_date] datetime  NULL,
    [customer_id] int  NULL,
    [employee_id] int  NULL,
    [total] float  NULL
);
GO

-- Creating table 'Vouchers'
CREATE TABLE [dbo].[Vouchers] (
    [ma_voucher] int IDENTITY(1,1) NOT NULL,
    [gia_voucher] float  NULL
);
GO

-- Creating table 'Customers'
CREATE TABLE [dbo].[Customers] (
    [customer_id] int  NOT NULL,
    [customer_name] nvarchar(50)  NULL,
    [customer_address] nvarchar(50)  NULL,
    [tolal] float  NULL
);
GO

-- --------------------------------------------------
-- Creating all PRIMARY KEY constraints
-- --------------------------------------------------

-- Creating primary key on [Account1] in table 'Accounts'
ALTER TABLE [dbo].[Accounts]
ADD CONSTRAINT [PK_Accounts]
    PRIMARY KEY CLUSTERED ([Account1] ASC);
GO

-- Creating primary key on [employee_id] in table 'Employees'
ALTER TABLE [dbo].[Employees]
ADD CONSTRAINT [PK_Employees]
    PRIMARY KEY CLUSTERED ([employee_id] ASC);
GO

-- Creating primary key on [item_id] in table 'Items'
ALTER TABLE [dbo].[Items]
ADD CONSTRAINT [PK_Items]
    PRIMARY KEY CLUSTERED ([item_id] ASC);
GO

-- Creating primary key on [order_id], [item_id] in table 'Lineitems'
ALTER TABLE [dbo].[Lineitems]
ADD CONSTRAINT [PK_Lineitems]
    PRIMARY KEY CLUSTERED ([order_id], [item_id] ASC);
GO

-- Creating primary key on [order_id] in table 'Orders'
ALTER TABLE [dbo].[Orders]
ADD CONSTRAINT [PK_Orders]
    PRIMARY KEY CLUSTERED ([order_id] ASC);
GO

-- Creating primary key on [ma_voucher] in table 'Vouchers'
ALTER TABLE [dbo].[Vouchers]
ADD CONSTRAINT [PK_Vouchers]
    PRIMARY KEY CLUSTERED ([ma_voucher] ASC);
GO

-- Creating primary key on [customer_id] in table 'Customers'
ALTER TABLE [dbo].[Customers]
ADD CONSTRAINT [PK_Customers]
    PRIMARY KEY CLUSTERED ([customer_id] ASC);
GO

-- --------------------------------------------------
-- Creating all FOREIGN KEY constraints
-- --------------------------------------------------

-- Creating foreign key on [employee_account] in table 'Employees'
ALTER TABLE [dbo].[Employees]
ADD CONSTRAINT [FK__Employee__employ__1CF15040]
    FOREIGN KEY ([employee_account])
    REFERENCES [dbo].[Accounts]
        ([Account1])
    ON DELETE NO ACTION ON UPDATE NO ACTION;
GO

-- Creating non-clustered index for FOREIGN KEY 'FK__Employee__employ__1CF15040'
CREATE INDEX [IX_FK__Employee__employ__1CF15040]
ON [dbo].[Employees]
    ([employee_account]);
GO

-- Creating foreign key on [employee_id] in table 'Orders'
ALTER TABLE [dbo].[Orders]
ADD CONSTRAINT [FK__Orders__employee__1DE57479]
    FOREIGN KEY ([employee_id])
    REFERENCES [dbo].[Employees]
        ([employee_id])
    ON DELETE NO ACTION ON UPDATE NO ACTION;
GO

-- Creating non-clustered index for FOREIGN KEY 'FK__Orders__employee__1DE57479'
CREATE INDEX [IX_FK__Orders__employee__1DE57479]
ON [dbo].[Orders]
    ([employee_id]);
GO

-- Creating foreign key on [item_id] in table 'Lineitems'
ALTER TABLE [dbo].[Lineitems]
ADD CONSTRAINT [FK__Lineitem__item_i__1FCDBCEB]
    FOREIGN KEY ([item_id])
    REFERENCES [dbo].[Items]
        ([item_id])
    ON DELETE NO ACTION ON UPDATE NO ACTION;
GO

-- Creating non-clustered index for FOREIGN KEY 'FK__Lineitem__item_i__1FCDBCEB'
CREATE INDEX [IX_FK__Lineitem__item_i__1FCDBCEB]
ON [dbo].[Lineitems]
    ([item_id]);
GO

-- Creating foreign key on [order_id] in table 'Lineitems'
ALTER TABLE [dbo].[Lineitems]
ADD CONSTRAINT [FK__Lineitem__order___1ED998B2]
    FOREIGN KEY ([order_id])
    REFERENCES [dbo].[Orders]
        ([order_id])
    ON DELETE NO ACTION ON UPDATE NO ACTION;
GO

-- Creating foreign key on [customer_id] in table 'Orders'
ALTER TABLE [dbo].[Orders]
ADD CONSTRAINT [FK__Orders__customer__1BFD2C07]
    FOREIGN KEY ([customer_id])
    REFERENCES [dbo].[Customers]
        ([customer_id])
    ON DELETE NO ACTION ON UPDATE NO ACTION;
GO

-- Creating non-clustered index for FOREIGN KEY 'FK__Orders__customer__1BFD2C07'
CREATE INDEX [IX_FK__Orders__customer__1BFD2C07]
ON [dbo].[Orders]
    ([customer_id]);
GO

-- --------------------------------------------------
-- Script has ended
-- --------------------------------------------------