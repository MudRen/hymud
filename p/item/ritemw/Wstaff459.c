// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit STAFF;

string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"anqi_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

void create()
{
	set_name("[31mÓã³¦Ö®ÕÈ[2;37;0m", ({ "yuchang staff", "staff" }));
	set_weight(12005);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "¸ù");
		set("long", @LONG
[31mÓã³¦ÇáÇÉÎŞ±È£¬ÄÜ¿ªÌì±ÙµØ£¬µ´Ñı³ıÄ§£¡
[2;37;0mÕâÊÇÒ»¸ùÓÉÎŞ±È¼áÓ²µÄ[1;37mÈíÒø[2;37;0mÖÆ³É£¬ÖØ¶şÊ®ËÄ½ïÁãÁ½Ò»Ç®µÄ[31mÓã³¦Ö®ÕÈ[2;37;0m¡£
×ÛºÏÆÀ¼Û[35m»ÙÌìÃğµØ[2;37;0m ¿´ÆğÀ´ÎŞ±È·æÀû£¬¾ßÓĞ[1;31m¿ªÔª´´ÊÀ[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;34mµç[2;37;0m:[1;31m´´ÊÀ[2;37;0m [37mÌì[2;37;0m:[1;31m´´ÊÀ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;33mÃğÊÀ[2;37;0m ÌìÁé:[32m´Ö²Ú[2;37;0m ÉÁµç:[35m±ê×¼[2;37;0m 
ÍşÁ¦:[32m´Ö²Ú[2;37;0m 

LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 36000);
		set("weapon_prop/intelligence",37);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 57);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 37);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",14);
    set("wtypeI",14);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "unarmed",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 23);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_staff(1362);
	setup();
}



#include "/obj/ritem/weaponzy.h";