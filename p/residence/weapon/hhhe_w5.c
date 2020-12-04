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
	set_name("[1;31m¶¬Ã·Ö®½£[2;37;0m", ({ "good sword", "sword" }));
	set_weight(9712);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("long", @LONG
¶¬Ã·Ö®½£[2;37;0mÕâÊÇÒ»°ÑÓÉ·Ç³£¼áÓ²µÄ[1;37mÈíÒø[2;37;0mÖÆ³É£¬ÖØÊ®¾Å½ïËÄÁ½¶şÇ®µÄ[1;31m¶¬Ã·Ö®½£[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;34m¾ÙÊÀº±¼û[2;37;0m ¿´ÆğÀ´·Ç³£·æÀû£¬¾ßÓĞ[35m¼«Æä¿ÉÅÂ[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;33m½ğ[2;37;0m:[35m±ê×¼[2;37;0m [36mÄ¾[2;37;0m:[33mºÜ¸ß[2;37;0m [32mË®[2;37;0m:[1;33mÌìÊ¥[2;37;0m [33mÍÁ[2;37;0m:[1;33mÌìÊ¥[2;37;0m [1;37mÀ×[2;37;0m:[1;36mÍêÃÀ[2;37;0m [1;34mµç[2;37;0m:[1;33mÌìÊ¥[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;33mÌìÊ¥[2;37;0m ÇÉÖÆ:[36m²»´í[2;37;0m 
×ÏÊ¯:[34mÏ¸Ëé[2;37;0m ³¤Éú:[36m²»´í[2;37;0m ²»ÀÏ:[36m²»´í[2;37;0m ÍşÁ¦:[32m´Ö²Ú[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32m¶¾Ã×[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÇá¹¦[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "hhhe");
		set("ownername", "¶¾Ã×");
		set("value", 9000);
		set("weapon_prop/intelligence",40);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 21);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 14);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 16);
    set("weapon_prop/jing", 19);
    set("weapon_prop/jingli", 19);
    set("weapon_prop/damage", 36);

    set("wtypeA",5);
    set("wtypeB",4);
    set("wtypeC",10);
    set("wtypeD",0);
    set("wtypeE",10);
    set("wtypeF",0);
    set("wtypeG",7);
    set("wtypeH",10);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "dodge",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 240,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 10);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_sword(389);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";