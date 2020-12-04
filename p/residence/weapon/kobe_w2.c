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
	set_name("[37mÉúËÀÖ®½£[2;37;0m", ({ "shengsi sword", "sword" }));
	set_weight(3764);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("long", @LONG
[37mÉúËÀÖ®½£[2;37;0mÕâÊÇÒ»°ÑÓÉÎŞ±È¼áÓ²µÄ[1;37mÈíÒø[2;37;0mÖÆ³É£¬ÖØÆß½ïÎåÁ½¶şÇ®µÄ[37mÉúËÀÖ®½£[2;37;0m¡£
×ÛºÏÆÀ¼Û[37m¾øÊÀÎŞË«[2;37;0m ¿´ÆğÀ´ÎŞ±È·æÀû£¬¾ßÓĞ[1;35m¾øÊÀº±¼û[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;36mÈË[2;37;0m:[31m¾«ÖÂ[2;37;0m [36mÄ¾[2;37;0m:[1;35m¾øÊÀ[2;37;0m [32mË®[2;37;0m:[1;36mÍêÃÀ[2;37;0m [31m»ğ[2;37;0m:[33mºÜ¸ß[2;37;0m [33mÍÁ[2;37;0m:[1;33mÌìÊ¥[2;37;0m [1;37mÀ×[2;37;0m:[1;33mÌìÊ¥[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;31mÎŞË«[2;37;0m ÌåÁé:[32m´Ö²Ú[2;37;0m °×Ê¯:[36m²»´í[2;37;0m ×ÏÊ¯:[36m²»´í[2;37;0m ÉÁµç:[33mºÜ¸ß[2;37;0m 
³¤Éú:[35m±ê×¼[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32m¿Æ±È[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÈ­·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "kobe");
		set("ownername", "¿Æ±È");
		set("value", 16000);
		set("weapon_prop/intelligence",32);
		set("weapon_prop/strength",40);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",40);
		set("weapon_prop/constitution",40);
    set("weapon_prop/dodge", 17);
    set("weapon_prop/parry", 17);
    set("weapon_prop/attack", 42);
    set("weapon_prop/armor", 32);
    set("weapon_prop/defense", 35);
    
    set("weapon_prop/neili", 24);
    set("weapon_prop/qi", 54);
    set("weapon_prop/jing", 32);
    set("weapon_prop/jingli", 24);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",11);
    set("wtypeC",7);
    set("wtypeD",4);
    set("wtypeE",10);
    set("wtypeF",0);
    set("wtypeG",10);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",3);
    set("wtypeK",6);
    set("wtypeL",4);
    

                set("skill", ([
                        "name": "cuff",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 15);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_sword(1322);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";