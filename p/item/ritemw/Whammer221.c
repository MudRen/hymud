// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit HAMMER;

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
	set_name("[37mÉñÖñÖ®´¸[2;37;0m", ({ "good hammer", "hammer" }));
	set_weight(8798);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "±ú");
		set("long", @LONG
ÉñÖñÖ®´¸[2;37;0mÕâÊÇÒ»±úÓÉ¾ø¶Ô¼áÓ²µÄ[33mÈíÌú[2;37;0mÖÆ³É£¬ÖØÊ®Æß½ïÎåÁ½¾ÅÇ®µÄ[37mÉñÖñÖ®´¸[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;34m¾ÙÊÀº±¼û[2;37;0m ¿´ÆğÀ´¾ø¶Ô·æÀû£¬¾ßÓĞ[35m¼«Æä¿ÉÅÂ[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;35m·ç[2;37;0m:[1;32mÄ§Íõ[2;37;0m 
[37mÌì[2;37;0m:[1;33mÌìÊ¥[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;31mÎŞË«[2;37;0m ÌìÁé:[36m²»´í[2;37;0m ÇÉÖÆ:[36m²»´í[2;37;0m 
³¤Éú:[32m´Ö²Ú[2;37;0m ²»ÀÏ:[36m²»´í[2;37;0m 

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
		set("weapon_prop/intelligence",18);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 13);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 32);
    set("weapon_prop/jing", 16);
    set("weapon_prop/jingli", 16);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",9);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",10);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "axe",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 240,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 12);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_hammer(386);
	setup();
}



#include "/obj/ritem/weaponzy.h";