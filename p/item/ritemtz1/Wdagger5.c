// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit DAGGER;

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
	set_name("[31mÁúÈªÖ®Ø°Ê×[2;37;0m¡ï", ({ "longquan dagger", "dagger" }));
	set_weight(3990);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("long", @LONG
[31mÁúÈªÈË¼ä¼«Æ·£¬ÎäÁÖÖÁ±¦£¡
[2;37;0mÕâÊÇÒ»°ÑÓÉÎŞ±È¼áÓ²µÄ[1;37mÈíÒø[2;37;0mÖÆ³É£¬ÖØÆß½ï¾ÅÁ½°ËÇ®µÄ[31mÁúÈªÖ®Ø°Ê×[2;37;0m¡£
×ÛºÏÆÀ¼Û[35m»ÙÌìÃğµØ[2;37;0m ¿´ÆğÀ´ÎŞ±È·æÀû£¬¾ßÓĞ[1;31m¿ªÔª´´ÊÀ[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[32mË®[2;37;0m:[1;33mÃğÊÀ[2;37;0m [1;35m·ç[2;37;0m:[1;33mÃğÊÀ[2;37;0m 
[1;37mÀ×[2;37;0m:[1;33mÌìÊ¥[2;37;0m [37mÌì[2;37;0m:[1;31m»ÙÌì[2;37;0m [1;31mÄ§[2;37;0m:[1;31mÎŞË«[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;33mÃğÊÀ[2;37;0m ¾ø´ú:[33mºÜ¸ß[2;37;0m ÌåÁé:[33mºÜ¸ß[2;37;0m °×Ê¯:[35m±ê×¼[2;37;0m ²»ÀÏ:[1;32mÄ§Íõ[2;37;0m ÍşÁ¦:[33mºÜ¸ß[2;37;0m 

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
		set("weapon_prop/percao",47);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 56);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 49);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 95);
    set("weapon_prop/jingli", 95);
    set("weapon_prop/damage", 47);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",16);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",16);
    set("wtypeG",10);
    set("wtypeH",0);
    set("wtypeI",15);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",12);
    

                set("skill", ([
                        "name": "whip",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 20);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_dagger(1483);
	setup();
}



#include "/obj/ritem/weaponzy.h";