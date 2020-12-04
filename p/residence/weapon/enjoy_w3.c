// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit SWORD;

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
	set_name("[1;33mÔÂÃ¢[2;37;0m", ({ "taiji sword", "sword" }));
	set_weight(3869);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("long", @LONG
[1;33mÌ«¼«Õß£¬ÎŞ¼«¶øÉú£¬ÒõÑôÖ®Ä¸Ò²¡£¶¯Ö®Ôò·Ö£¬¾²Ö®ÔòºÏ¡£ÎŞ¹ı²»¼°£¬ËæÇú¾ÍÉì¡£
ÈË¸ÕÎÒÈáÎ½Ö®×ß£¬ÎÒË³ÈË±³Î½Ö®Õ³¡£¶¯¼±Ôò¼±Ó¦£¬¶¯»ºÔò»ºËæ¡£Ëä±ä»¯Íò¶Ë£¬¶ø
ÀíÎªÒ»¹á£¡
[2;37;0mÕâÊÇÒ»°ÑÓÉÎŞ±È¼áÓ²µÄ[31mÍòÄêÉñÌú[2;37;0mÖÆ³É£¬ÖØÆß½ïÆßÁ½ÈıÇ®µÄ[1;33mÌ«¼«Ö®½£[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´ÎŞ±È·æÀû£¬¾ßÓĞ[1;35m¾øÊÀº±¼û[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;33m½ğ[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m [36mÄ¾[2;37;0m:[1;31m¿ªÔª[2;37;0m [32mË®[2;37;0m:[1;33mÌìÊ¥[2;37;0m [33mÍÁ[2;37;0m:[35m±ê×¼[2;37;0m [1;35m·ç[2;37;0m:[1;31m´´ÊÀ[2;37;0m 

ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;33mÃğÊÀ[2;37;0m ¸£Ô´:[32m´Ö²Ú[2;37;0m 
ÇÉÖÆ:[32m´Ö²Ú[2;37;0m 
ÌåÁé:[35m±ê×¼[2;37;0m °×Ê¯:[31m¾«ÖÂ[2;37;0m ÖÜÌì:[35m±ê×¼[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32m»¨ÎŞÀâ[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32m½£·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "enjoy");
		set("ownername", "»¨ÎŞÀâ");
		set("value", 25000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",34);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 60);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 31);
    set("weapon_prop/defense", 53);
    
    set("weapon_prop/neili", 59);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",8);
    set("wtypeB",13);
    set("wtypeC",10);
    set("wtypeD",0);
    set("wtypeE",5);
    set("wtypeF",14);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "sword",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 16);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_sword(920);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";