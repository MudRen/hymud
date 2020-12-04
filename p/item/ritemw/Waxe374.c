// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit AXE;

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
	set_name("[37mÂÌÓñÖ®¸«[2;37;0m", ({ "luyu axe", "axe" }));
	set_weight(12930);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "±ú");
		set("long", @LONG
[37mÂÌÓñÖ®¸«[2;37;0mÕâÊÇÒ»±úÓÉÎŞ±È¼áÓ²µÄ[1;32mÂÌÊ¯[2;37;0mÖÆ³É£¬ÖØ¶şÊ®Îå½ï°ËÁ½ÁùÇ®µÄ[37mÂÌÓñÖ®¸«[2;37;0m¡£
×ÛºÏÆÀ¼Û[37m¾øÊÀÎŞË«[2;37;0m ¿´ÆğÀ´ÎŞ±È·æÀû£¬¾ßÓĞ[35m¼«Æä¿ÉÅÂ[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[36mÄ¾[2;37;0m:[35m±ê×¼[2;37;0m [37mÌì[2;37;0m:[33mºÜ¸ß[2;37;0m [1;36mÈË[2;37;0m:[33mºÜ¸ß[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;31m´´ÊÀ[2;37;0m ÌìÓî:[36m²»´í[2;37;0m ¸£Ô´:[34mÏ¸Ëé[2;37;0m 
ÌåÁé:[35m±ê×¼[2;37;0m °×Ê¯:[34mÏ¸Ëé[2;37;0m ×ÏÊ¯:[33mºÜ¸ß[2;37;0m ÉÁµç:[34mÏ¸Ëé[2;37;0m 
³¤Éú:[34mÏ¸Ëé[2;37;0m 

LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 16000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",19);
		set("weapon_prop/karey",22);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 23);
    set("weapon_prop/parry", 43);
    set("weapon_prop/attack", 28);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 54);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 29);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",5);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",4);
    set("wtypeJ",0);
    set("wtypeK",4);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "sword",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 14);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_axe(412);
	setup();
}



#include "/obj/ritem/weaponzy.h";