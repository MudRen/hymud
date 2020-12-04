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
	set_name("[37mĞ¡Ö®¹÷[2;37;0m", ({ "bad club", "club" }));
	set_weight(6100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "¸ù");
		set("long", @LONG
Ğ¡Ö®¹÷[2;37;0mÕâÊÇÒ»¸ùÓÉ»¹Ëã¼áÓ²µÄ[32mÇàÍ­[2;37;0mÖÆ³É£¬ÖØÊ®¶ş½ï¶şÁ½ÁãÇ®µÄ[37mĞ¡Ö®¹÷[2;37;0m¡£
×ÛºÏÆÀ¼Û[32m¾«ÖÂÏ¸ÃÀ[2;37;0m ¿´ÆğÀ´»¹Ëã·æÀû£¬¾ßÓĞ[35m¼«Æä¿ÉÅÂ[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[36mÄ¾[2;37;0m:[33mºÜ¸ß[2;37;0m [40mµØ[2;37;0m:[32m´Ö²Ú[2;37;0m [1;31mÄ§[2;37;0m:[31m¾«ÖÂ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[35m±ê×¼[2;37;0m ÌìÓî:[32m¼«²î[2;37;0m ¾ø´ú:[32m¼«²î[2;37;0m ÇÉÖÆ:[33mÒ»°ã[2;37;0m 
ÌåÁé:[33mÒ»°ã[2;37;0m ×ÏÊ¯:[32m¼«²î[2;37;0m 

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
		set("weapon_prop/strength",4);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",3);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 2);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 9);
    set("weapon_prop/defense", 10);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",4);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",3);
    set("wtypeK",0);
    set("wtypeL",6);
    

                set("skill", ([
                        "name": "hammer",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 50,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 5);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_club(349);
	setup();
}



#include "/obj/ritem/weaponzy.h";