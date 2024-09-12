create database BT2_CNPM
go

use BT2_CNPM
go

create table Thedocgia
(
	Ma_docgia int primary key,
	Ten_docgia nvarchar(50),
	Email varchar(50),
	Diachi nvarchar(50),
	Sdt char(15)
)


create table Sach
(
	Ma_sach int primary key,
	Ten_sach nvarchar(50),
	Tacgia nvarchar(50),
	Vi_tri varchar(10),
	Tinhtrang nvarchar(10)
)

create table Thuthu
(
	Ma_thuthu int primary key identity(1,1),
	Gio_truc varchar(30),
	Ghi_chu	nvarchar(50)
)

create table Muon_sach
(
	Ma_muon int primary key,
	Ma_docgia int,
	thoigian_muon datetime,
	thoigian_tra datetime,
	Ma_thuthu int,
	tinhtrang nvarchar(10)
)



create table Danhsach_muon
(
	Ma_muon int,
	Ma_sach int

	primary key(Ma_muon,Ma_sach)
)



create table Thu_vien
(
	Gio_lam nvarchar(50) primary key,
	Diachi nvarchar(50),
	Sdt char(15),
	Ghichu nvarchar(50)
)



Alter table Muon_sach
Add foreign key (Ma_docgia) references Thedocgia(Ma_docgia)

Alter table Muon_sach
Add foreign key (Ma_thuthu) references Thuthu(Ma_thuthu)

Alter table Danhsach_muon
add foreign key (Ma_muon) references Muon_sach(Ma_muon)

Alter table Danhsach_muon
add foreign key (Ma_sach) references Sach(Ma_sach)

insert into Thedocgia values(1,N'Lê Tuấn Nghĩa','letuannghia22@gmail.com','acasvaa','0909383703')
insert into Thu_vien values (N'8 giờ - 12 giờ và 13 giờ - 17 giờ',N'số 1 Võ Văn Ngân, TP.Thủ Đức','0123456789',N'Lưu ý: Chủ nhật không hoạt động')
insert into Thuthu values('ca 1 thu 2-4-6','')
insert into Thuthu values('ca 1 thu 2-4-6','')
insert into Thuthu values('ca 2 thu 2-4-6','')
insert into Thuthu values('ca 2 thu 2-4-6','')
insert into Thuthu values('ca 1 thu 3-5-7','')
insert into Thuthu values('ca 1 thu 3-5-7','')
insert into Thuthu values('ca 2 thu 3-5-7','')
insert into Thuthu values('ca 2 thu 3-5-7','')
