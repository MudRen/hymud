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
	set_name("[1;37mĞı·çÖ®µ¶[2;37;0m", ({ "general blade", "blade" }));
	set_weight(3628);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "±ú");
		set("long", @LONG
Ğı·çÖ®µ¶[2;37;0mÕâÊÇÒ»±úÓÉÏàµ±¼áÓ²µÄ[33mÉúÌú[2;37;0mÖÆ³É£¬ÖØÆß½ï¶şÁ½ÎåÇ®µÄ[1;37mĞı·çÖ®µ¶[2;37;0m¡£
×ÛºÏÆÀ¼Û[31mÍêÃÀ¾«ÖÂ[2;37;0m ¿´ÆğÀ´Ïàµ±·æÀû£¬¾ßÓĞ[32mË®×¼ÒÔÉÏ[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[31m»ğ[2;37;0m:[34mÏ¸Ëé[2;37;0m [1;35m·ç[2;37;0m:[33mºÜ¸ß[2;37;0m 
[40mµØ[2;37;0m:[31m¾«ÖÂ[2;37;0m [1;31mÄ§[2;37;0m:[31m¾«ÖÂ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[31m¾«ÖÂ[2;37;0m ÖÜÌì:[36m²»´í[2;37;0m ÍşÁ¦:[33mÒ»°ã[2;37;0m 

LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 2000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 13);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 7);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",2);
    set("wtypeE",0);
    set("wtypeF",4);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",6);
    set("wtypeK",0);
    set("wtypeL",6);
    

                set("skill", ([
                        "name": "unarmed",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 120,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 6);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_blade(182);
	setup();
}



#include "/obj/ritem/weaponzy.h";