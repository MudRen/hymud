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
	set_name("[1;31mÁ÷¹âĞÇÓ°½£[2;37;0m", ({ "wuji sword", "sword" }));
	set_weight(7927);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("long", @LONG
[1;32m´ËÎïÒÑ´ï³öÉñÈë»¯£¬µÇ·åÔì¼«£¬ÉñºõÆäÉñÖ®¾³½ç£¡Ë×ËµÍòÎï¹é×Ú£¬±ãÊÇÕâ¡°ÎŞ¼«¡±£¡
[2;37;0mÕâÊÇÒ»°ÑÓÉ¾ø¶Ô¼áÓ²µÄ[37mĞşÌú[2;37;0mÖÆ³É£¬ÖØÊ®Îå½ï°ËÁ½ÎåÇ®µÄ[1;32mÎŞ¼«Ö®½£[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´¾ø¶Ô·æÀû£¬¾ßÓĞ[1;33m¾ÙÊÀÎŞÆ¥[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;31mÄ§[2;37;0m:[1;35m¾øÊÀ[2;37;0m [32mË®[2;37;0m:[1;36mÍêÃÀ[2;37;0m [1;35m·ç[2;37;0m:[1;36mÍêÃÀ[2;37;0m 
[1;37mÀ×[2;37;0m:[1;31m´´ÊÀ[2;37;0m [1;34mµç[2;37;0m:[1;35m¾øÊÀ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;31m»ÙÌì[2;37;0m ÌìÁé:[34mÏ¸Ëé[2;37;0m ¸£Ô´:[34mÏ¸Ëé[2;37;0m 
ÌìĞş:[32m´Ö²Ú[2;37;0m ÉÁµç:[33mºÜ¸ß[2;37;0m 
³¤Éú:[35m±ê×¼[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mĞÇÒş[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÈ­½Å[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "bbm");
		set("ownername", "ĞÇÒş");
		set("value", 25000);
		set("weapon_prop/intelligence",27);
		set("weapon_prop/strength",24);
		set("weapon_prop/karey",28);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",40);
		set("weapon_prop/constitution",36);
    set("weapon_prop/dodge", 32);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 43);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 32);
    
    set("weapon_prop/neili", 40);
    set("weapon_prop/qi", 50);
    set("weapon_prop/jing", 24);
    set("weapon_prop/jingli", 32);
    set("weapon_prop/damage", 48);

    set("wtypeA",0);
    set("wtypeB",4);
    set("wtypeC",7);
    set("wtypeD",3);
    set("wtypeE",0);
    set("wtypeF",7);
    set("wtypeG",14);
    set("wtypeH",11);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",3);
    set("wtypeL",11);
    

                set("skill", ([
                        "name": "unarmed",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 15);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_sword(1052);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";