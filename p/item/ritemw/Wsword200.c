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
	set_name("[1;35mÖñÒ¶Ö®½£[2;37;0m", ({ "good sword", "sword" }));
	set_weight(6083);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("long", @LONG
ÖñÒ¶Ö®½£[2;37;0mÕâÊÇÒ»°ÑÓÉÏàµ±¼áÓ²µÄ[33mÈíÌú[2;37;0mÖÆ³É£¬ÖØÊ®¶ş½ïÒ»Á½ÁùÇ®µÄ[1;35mÖñÒ¶Ö®½£[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;34m¾ÙÊÀº±¼û[2;37;0m ¿´ÆğÀ´Ïàµ±·æÀû£¬¾ßÓĞ[1;34mÒĞÌìÍÀÁú[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[33mÍÁ[2;37;0m:[1;32mÄ§Íõ[2;37;0m [1;37mÀ×[2;37;0m:[33mºÜ¸ß[2;37;0m [1;34mµç[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m [40mµØ[2;37;0m:[33mºÜ¸ß[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;35m¾øÊÀ[2;37;0m ÌìÁé:[36m²»´í[2;37;0m ÇÉÖÆ:[34mÏ¸Ëé[2;37;0m 
²»ÀÏ:[32m´Ö²Ú[2;37;0m 

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
		set("weapon_prop/intelligence",13);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 24);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 32);
    set("weapon_prop/jingli", 32);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",9);
    set("wtypeF",0);
    set("wtypeG",4);
    set("wtypeH",8);
    set("wtypeI",0);
    set("wtypeJ",4);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "leg",
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
	
	init_sword(698);
	setup();
}



#include "/obj/ritem/weaponzy.h";