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
	set_name("[31mÌ«°¢Ö®½£[2;37;0m", ({ "taie sword", "sword" }));
	set_weight(14625);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("long", @LONG
[31mÌ«°¢µÛÍõÖ®±ø£¬³ÖÖ®ÄÜºÅÁîÌìÏÂ£¬ÄªÓĞ²»´Ó£¡
[2;37;0mÕâÊÇÒ»°ÑÓÉÎŞ±È¼áÓ²µÄ[1;37mÈíÒø[2;37;0mÖÆ³É£¬ÖØ¶şÊ®¾Å½ï¶şÁ½ÎåÇ®µÄ[31mÌ«°¢Ö®½£[2;37;0m¡£
×ÛºÏÆÀ¼Û[35m»ÙÌìÃğµØ[2;37;0m ¿´ÆğÀ´ÎŞ±È·æÀû£¬¾ßÓĞ[1;33m¾ÙÊÀÎŞÆ¥[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;33mÃğÊÀ[2;37;0m ÌìÔ¨:[33mºÜ¸ß[2;37;0m ÇÉÖÆ:[1;34m¾ÙÊÀ[2;37;0m 
ÌåÁé:[31m¾«ÖÂ[2;37;0m °×Ê¯:[33mºÜ¸ß[2;37;0m ×ÏÊ¯:[33mºÜ¸ß[2;37;0m ÖÜÌì:[31m¾«ÖÂ[2;37;0m ³¤Éú:[1;34m¾ÙÊÀ[2;37;0m ²»ÀÏ:[1;34m¾ÙÊÀ[2;37;0m 

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
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",47);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 43);
    set("weapon_prop/parry", 40);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 88);
    set("weapon_prop/defense", 66);
    
    set("weapon_prop/neili", 69);
    set("weapon_prop/qi", 82);
    set("weapon_prop/jing", 80);
    set("weapon_prop/jingli", 80);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "leg",
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
	
	init_sword(915);
	setup();
}



#include "/obj/ritem/weaponzy.h";