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
	set_name("[1;34mÌ¾Ï¢[2;37;0m", ({ "shengxie sword", "sword" }));
	set_weight(9908);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("long", @LONG
[31mÊ¤Ğ°ÍşÁ¦¾Ş´ó¶øÎŞÈÎºÎÒªÇó£¡
[2;37;0mÕâÊÇÒ»°ÑÓÉÎŞ±È¼áÓ²µÄ[1;36mÍòÄêº®±ùÌú[2;37;0mÖÆ³É£¬ÖØÊ®¾Å½ï°ËÁ½Ò»Ç®µÄ[31mÊ¤Ğ°Ö®½£[2;37;0m¡£
×ÛºÏÆÀ¼Û[35m»ÙÌìÃğµØ[2;37;0m ¿´ÆğÀ´ÎŞ±È·æÀû£¬¾ßÓĞ[1;35m¾øÊÀº±¼û[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;33m½ğ[2;37;0m:[1;31m´´ÊÀ[2;37;0m [36mÄ¾[2;37;0m:[1;35m¾øÊÀ[2;37;0m [32mË®[2;37;0m:[1;33mÃğÊÀ[2;37;0m [31m»ğ[2;37;0m:[1;35m¾øÊÀ[2;37;0m [33mÍÁ[2;37;0m:[1;33mÃğÊÀ[2;37;0m [1;37mÀ×[2;37;0m:[1;31m¿ªÔª[2;37;0m [1;34mµç[2;37;0m:[1;36mÍêÃÀ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;33mÃğÊÀ[2;37;0m ÌìÁé:[32m´Ö²Ú[2;37;0m ¸£Ô´:[33mºÜ¸ß[2;37;0m 
ÇÉÖÆ:[1;36mÍêÃÀ[2;37;0m 
ÌåÁé:[1;34m¾ÙÊÀ[2;37;0m ×ÏÊ¯:[33mºÜ¸ß[2;37;0m ²»ÀÏ:[31m¾«ÖÂ[2;37;0m ÍşÁ¦:[1;34m¾ÙÊÀ[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32m·Éºü[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mµ¶·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "feihu");
		set("ownername", "·Éºü");
		set("value", 36000);
		set("weapon_prop/intelligence",36);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",47);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 42);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 72);
    set("weapon_prop/defense", 83);
    
    set("weapon_prop/neili", 72);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 62);
    set("weapon_prop/jingli", 62);
    set("weapon_prop/damage", 88);

    set("wtypeA",14);
    set("wtypeB",11);
    set("wtypeC",16);
    set("wtypeD",11);
    set("wtypeE",16);
    set("wtypeF",0);
    set("wtypeG",13);
    set("wtypeH",7);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "blade",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 26);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_sword(1057);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";