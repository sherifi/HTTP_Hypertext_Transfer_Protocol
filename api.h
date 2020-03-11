#pragma once
#include <vector>

typedef struct s_Person_Data
{
	const char*					m_person_first_name					=	"Sherifi";
	const char*					m_person_last_name						=	"Sherifi";
	const char*					m_person_middle_name					=	"KELO";
	unsigned short int 			m_person_age							=	25;
	const char*					m_person_city							=	"New York";
	const char*					m_person_country						=	"New York";
	const char*					m_person_state							=	"USA";
	const char*					m_person_gender					=	"male";
}s_Person_Data;

typedef struct s_User_data
{
	unsigned long long int		m_user_id						=	12739027321;
	const char*					m_user_name						=	"SHERIFI";
	const char*					m_user_photo					=	"profile_photo.jpg";
	const char*					m_user_profile_type				=	"Service";
	const char*					m_user_bio						=	"Bio of user";
	const char*					m_user_email					=	"sherifi_co@yahoo.com";
	unsigned long long int		m_user_phone					=	38971697957;
	const char*					m_user_web						=	"https:://www.sherifi_co.com";
}s_User_data;

typedef struct s_User_profile_data
{
	const char*					m_profile_page					=	"Artarchvogue";
	const char*					m_profile_category				=	"Service/Enterprice";
	const char*					m_profile_contact_options		=	"Email/Phone";
	const char*					m_profile_display				=	"None, Hiden";
}s_User_profile_data;

typedef struct s_Admin_Contact_info
{
	const char*					m_admin_email					=	"sherifi_co@yahoo.com";
	unsigned long long int		m_admin_phone					=	38971697957;

}s_Admin_Contact_info;

typedef struct s_Business_Categories_list
{
	std::vector<const char*> vec_A
	{
		"Advertising/Marketing",
		"Album",
		"Amateur Sports Team",
		"Apartment & Condo Building",
		"Appliance Repair Service",
		"App Page",
		"Architectural Designer",
		"Art",
		"Artist",
		"Arts & Entertainment",
		"Athlete",
		"Automotive Repair Shop"
	}
	std::vector<const char*> vec_B
	{
		"Baby & Children’s Clothing Store",
		"Baby Goods/Kids Goods",
		"Bar",
		"Beauty, Cosmetic & Personal Care",
		"Beauty Salon",
		"Book",
		"Business Center",
		"Business Service"
	}
	std::vector<const char*> vec_C
	{
		"Camera/Photo",
		"Canoe & Kayak Rental",
		"Chicken Joint",
		"Church of Christ",
		"Church of Jesus Christ of Latter-day Saints",
		"Clothing (Brand)",
		"Clothing Store",
		"College & University",
		"Commercial & Industrial",
		"Commercial & Industrial Equipment Supplier",
		"Commercial Bank",
		"Commercial Equipment",
		"Commercial Real Estate Agency",
		"Commercial Truck Dealership",
		"Community",
		"Community Organization",
		"Consulting Agency",
		"Contractor",
		"Convenience Store",
		"Credit Union"
	}
	std::vector<const char*> vec_D
	{
		"Doctor",
		"Deli",
		"Dancer",
		"Design & Fashion",
		"Dessert Shop",
		"Discount Store",
		"Dorm"
	}
	std::vector<const char*> vec_E
	{
		"E-Cigarette Store",
		"E-commerce Website",
		"Education",
		"Engineering Service",
		"Entertainment Website",
		"Entrepreneur",
		"Episode",
		"Event"
	}
	std::vector<const char*> vec_F
	{
		"Family Style Restaurant",
		"Fashion Designer",
		"Fashion Model",
		"Fast Food Restaurant",
		"Financial Service",
		"Food & Beverage",
		"Food Stand",
		"Footwear Store"
	}
	std::vector<const char*> vec_G
	{
		"Gamer",
		"Games/Toys",
		"Gaming Video Creator",
		"Government Organization",
		"Graphic Designer",
		"Grocery Store"
	}
	std::vector<const char*> vec_H
	{
		"Hardware Store",
		"Health/Beauty",
		"Heating, Ventilating & Air Conditioning Service",
		"Home Decor",
		"Home Improvement",
		"Hospital",
		"Hotel",
		"Hotel & Lodging"
	}
	std::vector<const char*> vec_I
	{
		"Ice Cream Shop",
		"In-Home Service",
		"Industrial Company",
		"Information Technology Company",
		"Insurance Company",
		"Interior Design Studio",
		"Internet Company",
		"Internet Marketing Service"
	}
	std::vector<const char*> vec_J
	{
		"Japanese Restaurant",
		"Jazz & Blues Club",
		"Jewelry/Watches",
		"Jewelry & Watches Company",
		"Journalist",
		"Just For Fun"
	}
	std::vector<const char*> vec_K
	{
		"Karaoke",
		"Kennel",
		"Kitchen & Bath Contractor",
		"Kitchen/Cooking",
		"Korean Restaurant"
	}
	std::vector<const char*> vec_L
	{
		"Landmark & Historical Place",
		"Lawyer & Law Firm",
		"Library",
		"Loan Service",
		"Local Service",
		"Lumber Yard"
	}
	std::vector<const char*> vec_M
	{
		"Marketing Agency",
		"Media",
		"Media/News Company",
		"Medical Center",
		"Medical School",
		"Men’s Clothing Store",
		"Mental Health Service",
		"Movie",
		"Musician/Band",
		"Music Lessons & Instruction School",
		"Music Video"
	}
	std::vector<const char*> vec_N
	{
		"News & Media Website",
		"Newspaper",
		"Nonprofit Organization",
		"Non-Governmental Organization (NGO)",
		"Not a Business",
		"Nursing Agency"
	}
	std::vector<const char*> vec_O
	{
		"Obstetrician-Gynecologist (OBGYN)",
		"Office Equipment Store",
		"Office Supplies",
		"Optician",
		"Optometrist",
		"Outdoor & Sporting Goods Company"
	}
	std::vector<const char*> vec_P
	{
		"Personal Blog",
		"Petting Zoo",
		"Photographer",
		"Product/Service",
		"Public & Government Service",
		"Public Figure",
		"Public Utility Company"
	}
	std::vector<const char*> vec_Q
	{
		"Quay"
	}
	std::vector<const char*> vec_R
	{
		"Real Estate",
		"Real Estate Agent",
		"Real Estate Appraiser",
		"Real Estate Company",
		"Real Estate Developer",
		"Record Label",
		"Religious Center",
		"Religious Organization",
		"Residence",
		"Restaurant",
		"Retail Bank"
	}
	std::vector<const char*> vec_S
	{
		"School",
		"Science, Technology & Engineering",
		"Shopping & Retail",
		"Shopping District",
		"Shopping Mall",
		"Smoothie & Juice Bar",
		"Song",
		"Specialty School",
		"Sports & Recreation",
		"Sports League",
		"Sports Team"
	}
	std::vector<const char*> vec_T
	{
		"Teens & Kids Website",
		"Telemarketing Service",
		"Tire Dealer & Repair Shop",
		"Trade School",
		"Traffic School",
		"Train Station",
		"Tutor/Teacher",
		"TV Channel",
		"TV Network",
		"TV Show"
	}
	std::vector<const char*> vec_U
	{
		"Udon Restaurant",
		"Ukranian Restaurant",
		"Unagi Restaurant",
		"Uniform Supplier",
		"Urban Farm"
	}
	std::vector<const char*> vec_V
	{
		"Vacation Home Rental",
		"Veterinarian",
		"Video Creator",
		"Video Game",
		"Visual Arts"
	}
	std::vector<const char*> vec_W
	{
		"Web Designer",
		"Website",
		"Wedding Planning Service",
		"Winery/Vineyard",
		"Women’s Clothing Store",
		"Women’s Health Clinic",
		"Writer"
	}
	std::vector<const char*> vec_X
	{
		"Xinjiang Restaurant"
	}
	std::vector<const char*> vec_Y
	{
		"Yakiniku Restaurant",
		"Yakitori Restaurant",
		"Yoga Studio",
		"Yoshoku Restaurant",
		"Youth Organization"
	}
	std::vector<const char*> vec_Z
	{
		"Zhejiang Restaurant",
		"Zoo"
	}
}s_Business_Categories_list;

