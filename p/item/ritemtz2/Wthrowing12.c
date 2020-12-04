// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit THROWING;

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
	set_name("[1;36mÈıÇåÖ®°µÆ÷[2;37;0m¡ï", ({ "sanqing throwing", "throwing" }));
	set_weight(312);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "Ö§");
		set("long", @LONG
[1;36m´óµÀÎŞÃû£¬¾ÛÆø³ÉĞÎ£¬¹¦²ÎÔì»¯£¬Ò»ÊÇÈıÇå£¡Õâ±ãÊÇ¡°ÀÏ×ÓÒ»î¸»¯ÈıÇå¡£¡±
[2;37;0mÕâÊÇÒ»Ö§ÓÉ¾ø¶Ô¼áÓ²µÄ[31mÁ÷»¨Ê¯[2;37;0mÖÆ³É£¬ÖØÁã½ïÁùÁ½¶şÇ®µÄ[1;36mÈıÇåÖ®°µÆ÷[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´¾ø¶Ô·æÀû£¬¾ßÓĞ[1;31mÌìÏÂÎŞË«[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;33m½ğ[2;37;0m:[1;33mÌìÊ¥[2;37;0m [1;37mÀ×[2;37;0m:[1;35m¾øÊÀ[2;37;0m [1;34mµç[2;37;0m:[1;35m¾øÊÀ[2;37;0m [1;31mÄ§[2;37;0m:[1;31m¿ªÔª[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;31m»ÙÌì[2;37;0m ÌìÔ¨:[34mÏ¸Ëé[2;37;0m ÖÜÌì:[31m¾«ÖÂ[2;37;0m ³¤Éú:[35m±ê×¼[2;37;0m 

LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 25000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",28);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 67);
    set("weapon_prop/qi", 56);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",10);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",11);
    set("wtypeH",11);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",13);
    

                set("skill", ([
                        "name": "parry",
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
	set_amount(1);
	init_throwing(1244);
	setup();
}



#include "/obj/ritem/weaponzy.h";