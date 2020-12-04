// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit CLUB;

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
	set_name("[35m±öÖ®¹÷[2;37;0m", ({ "bad club", "club" }));
	set_weight(15682);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "¸ù");
		set("long", @LONG
±öÖ®¹÷[2;37;0mÕâÊÇÒ»¸ùÓÉ¼«Æä¼áÓ²µÄ[32mÇàÍ­[2;37;0mÖÆ³É£¬ÖØÈıÊ®Ò»½ïÈıÁ½ÁùÇ®µÄ[35m±öÖ®¹÷[2;37;0m¡£
×ÛºÏÆÀ¼Û[32m¾«ÖÂÏ¸ÃÀ[2;37;0m ¿´ÆğÀ´¼«Æä·æÀû£¬¾ßÓĞ[32mË®×¼ÒÔÉÏ[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;33m½ğ[2;37;0m:[35m±ê×¼[2;37;0m [31m»ğ[2;37;0m:[35m±ê×¼[2;37;0m [33mÍÁ[2;37;0m:[34mÏ¸Ëé[2;37;0m [37mÌì[2;37;0m:[36m²»´í[2;37;0m [1;31mÄ§[2;37;0m:[36m²»´í[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[32m´Ö²Ú[2;37;0m ÌìÁé:[32m¼«²î[2;37;0m ÌìÓî:[32m¼«²î[2;37;0m ÍşÁ¦:[32m¼«²î[2;37;0m 

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
		set("weapon_prop/intelligence",2);
		set("weapon_prop/strength",5);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 3);

    set("wtypeA",5);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",5);
    set("wtypeE",2);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",1);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",1);
    

                set("skill", ([
                        "name": "unarmed",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 50,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 3);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_club(212);
	setup();
}



#include "/obj/ritem/weaponzy.h";