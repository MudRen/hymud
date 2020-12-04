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
	set_name("[1;33mĞÓ»¨·É[2;37;0m", ({ "wuji sword", "sword" }));
	set_weight(11762);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("long", @LONG
[1;32m´ËÎïÒÑ´ï³öÉñÈë»¯£¬µÇ·åÔì¼«£¬ÉñºõÆäÉñÖ®¾³½ç£¡Ë×ËµÍòÎï¹é×Ú£¬±ãÊÇÕâ¡°ÎŞ¼«¡±£¡
[2;37;0mÕâÊÇÒ»°ÑÓÉÎŞ±È¼áÓ²µÄ[37mĞşÌú[2;37;0mÖÆ³É£¬ÖØ¶şÊ®Èı½ïÎåÁ½¶şÇ®µÄ[1;32mÎŞ¼«Ö®½£[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´ÎŞ±È·æÀû£¬¾ßÓĞ[1;35m¾øÊÀº±¼û[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;31mÄ§[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m [1;33m½ğ[2;37;0m:[31m¾«ÖÂ[2;37;0m [31m»ğ[2;37;0m:[1;31m´´ÊÀ[2;37;0m [33mÍÁ[2;37;0m:[1;33mÌìÊ¥[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;33mÃğÊÀ[2;37;0m ¸£Ô´:[34mÏ¸Ëé[2;37;0m 
ÌìĞş:[34mÏ¸Ëé[2;37;0m ÇÉÖÆ:[33mºÜ¸ß[2;37;0m 
×ÏÊ¯:[32m´Ö²Ú[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mÏãÀïĞ¡[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32m½£·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "qing");
		set("ownername", "ÏãÀïĞ¡");
		set("value", 25000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",27);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",28);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 36);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 49);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",6);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",14);
    set("wtypeE",10);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",8);
    

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
	
	init_sword(985);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";