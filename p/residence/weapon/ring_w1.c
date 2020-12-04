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
	set_name("[1;36m·çÖ®Ó½Ì¾[2;37;0m", ({ "shengxie sword", "sword" }));
	set_weight(18916);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("long", @LONG
[31mÊ¤Ğ°ÍşÁ¦¾Ş´ó¶øÎŞÈÎºÎÒªÇó£¡
[2;37;0mÕâÊÇÒ»°ÑÓÉÎŞ±È¼áÓ²µÄ[1;36mÍòÄêº®±ùÌú[2;37;0mÖÆ³É£¬ÖØÈıÊ®Æß½ï°ËÁ½ÈıÇ®µÄ[31mÊ¤Ğ°Ö®½£[2;37;0m¡£
×ÛºÏÆÀ¼Û[35m»ÙÌìÃğµØ[2;37;0m ¿´ÆğÀ´ÎŞ±È·æÀû£¬¾ßÓĞ[1;31m»ÙÌìÃğµØ[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[36mÄ¾[2;37;0m:[1;31mÎŞË«[2;37;0m [32mË®[2;37;0m:[1;33mÃğÊÀ[2;37;0m [31m»ğ[2;37;0m:[1;31m»ÙÌì[2;37;0m [1;35m·ç[2;37;0m:[1;33mÌìÊ¥[2;37;0m 
[1;37mÀ×[2;37;0m:[1;36mÍêÃÀ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;33mÃğÊÀ[2;37;0m ÌìÁé:[33mºÜ¸ß[2;37;0m ÌìĞş:[32m´Ö²Ú[2;37;0m ÌåÁé:[33mºÜ¸ß[2;37;0m ×ÏÊ¯:[1;36mÍêÃÀ[2;37;0m ÉÁµç:[1;36mÍêÃÀ[2;37;0m 
ÖÜÌì:[35m±ê×¼[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mïLâ[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÖ¸·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "ring");
		set("ownername", "ïLâ");
		set("value", 36000);
		set("weapon_prop/intelligence",41);
		set("weapon_prop/strength",72);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",36);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 73);
    set("weapon_prop/attack", 71);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 40);
    
    set("weapon_prop/neili", 50);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 72);
    set("weapon_prop/jingli", 72);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",12);
    set("wtypeC",16);
    set("wtypeD",15);
    set("wtypeE",0);
    set("wtypeF",10);
    set("wtypeG",7);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",9);
    set("wtypeL",9);
    

                set("skill", ([
                        "name": "finger",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 19);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_sword(1705);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";