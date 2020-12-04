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
	set_name("[35mÆ®Ñ©Ö®½£[2;37;0m", ({ "general sword", "sword" }));
	set_weight(4131);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("long", @LONG
Æ®Ñ©Ö®½£[2;37;0mÕâÊÇÒ»°ÑÓÉÊ®·Ö¼áÓ²µÄ[33mÉúÌú[2;37;0mÖÆ³É£¬ÖØ°Ë½ï¶şÁ½ÁùÇ®µÄ[35mÆ®Ñ©Ö®½£[2;37;0m¡£
×ÛºÏÆÀ¼Û[31mÍêÃÀ¾«ÖÂ[2;37;0m ¿´ÆğÀ´Ê®·Ö·æÀû£¬¾ßÓĞ[32mË®×¼ÒÔÉÏ[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[36mÄ¾[2;37;0m:[33mºÜ¸ß[2;37;0m [1;35m·ç[2;37;0m:[31m¾«ÖÂ[2;37;0m 
[1;31mÄ§[2;37;0m:[35m±ê×¼[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[31m¾«ÖÂ[2;37;0m °×Ê¯:[36m²»´í[2;37;0m ×ÏÊ¯:[36m²»´í[2;37;0m ÉÁµç:[36m²»´í[2;37;0m 
ÖÜÌì:[36m²»´í[2;37;0m ²»ÀÏ:[36m²»´í[2;37;0m 

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
    set("weapon_prop/dodge", 13);
    set("weapon_prop/parry", 14);
    set("weapon_prop/attack", 16);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 13);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 19);
    set("weapon_prop/jingli", 19);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",4);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",6);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",5);
    

                set("skill", ([
                        "name": "axe",
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
	
	init_sword(222);
	setup();
}



#include "/obj/ritem/weaponzy.h";