// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit BLADE;

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
	set_name("[1;35m°µ¹âÖ®µ¶[2;37;0m", ({ "good blade", "blade" }));
	set_weight(2829);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "±ú");
		set("long", @LONG
°µ¹âÖ®µ¶[2;37;0mÕâÊÇÒ»±úÓÉ¾ø¶Ô¼áÓ²µÄ[33mÈíÌú[2;37;0mÖÆ³É£¬ÖØÎå½ïÁùÁ½ÎåÇ®µÄ[1;35m°µ¹âÖ®µ¶[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;34m¾ÙÊÀº±¼û[2;37;0m ¿´ÆğÀ´¾ø¶Ô·æÀû£¬¾ßÓĞ[1;36mÕ¶Ñı·üÄ§[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;33m½ğ[2;37;0m:[31m¾«ÖÂ[2;37;0m [1;35m·ç[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m 
[1;34mµç[2;37;0m:[1;33mÌìÊ¥[2;37;0m [37mÌì[2;37;0m:[32m´Ö²Ú[2;37;0m [40mµØ[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m [1;31mÄ§[2;37;0m:[33mºÜ¸ß[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;35m¾øÊÀ[2;37;0m ÌìÁé:[36m²»´í[2;37;0m ÌìÓî:[36m²»´í[2;37;0m ¾ø´ú:[36m²»´í[2;37;0m ×ÏÊ¯:[36m²»´í[2;37;0m ÉÁµç:[36m²»´í[2;37;0m 
²»ÀÏ:[34mÏ¸Ëé[2;37;0m 

LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 9000);
		set("weapon_prop/intelligence",12);
		set("weapon_prop/strength",14);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",11);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 12);
    set("weapon_prop/attack", 16);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 23);
    set("weapon_prop/jingli", 23);
    set("weapon_prop/damage", 0);

    set("wtypeA",6);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",8);
    set("wtypeG",0);
    set("wtypeH",10);
    set("wtypeI",3);
    set("wtypeJ",8);
    set("wtypeK",0);
    set("wtypeL",4);
    

                set("skill", ([
                        "name": "unarmed",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 240,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 11);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_blade(577);
	setup();
}



#include "/obj/ritem/weaponzy.h";