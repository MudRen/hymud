// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit WHIP;

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
	set_name("[1;31mÇ§ØğÖ®±Ş[2;37;0m", ({ "general whip", "whip" }));
	set_weight(11471);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "¸ù");
		set("long", @LONG
Ç§ØğÖ®±Ş[2;37;0mÕâÊÇÒ»¸ùÓÉ¾ø¶Ô¼áÓ²µÄ[33mÉúÌú[2;37;0mÖÆ³É£¬ÖØ¶şÊ®¶ş½ï¾ÅÁ½ËÄÇ®µÄ[1;31mÇ§ØğÖ®±Ş[2;37;0m¡£
×ÛºÏÆÀ¼Û[31mÍêÃÀ¾«ÖÂ[2;37;0m ¿´ÆğÀ´¾ø¶Ô·æÀû£¬¾ßÓĞ[34m²»´í[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[36mÄ¾[2;37;0m:[1;36mÍêÃÀ[2;37;0m [33mÍÁ[2;37;0m:[31m¾«ÖÂ[2;37;0m [1;35m·ç[2;37;0m:[1;36mÍêÃÀ[2;37;0m 
[1;31mÄ§[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[32m´Ö²Ú[2;37;0m ÌìÔ¨:[33mÒ»°ã[2;37;0m ÌìĞş:[32m¼«²î[2;37;0m ÇÉÖÆ:[36m²»´í[2;37;0m 
°×Ê¯:[36m²»´í[2;37;0m ÉÁµç:[32m¼«²î[2;37;0m 
²»ÀÏ:[36m²»´í[2;37;0m 

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
		set("weapon_prop/dexerity",9);
		set("weapon_prop/constitution",3);
    set("weapon_prop/dodge", 18);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 3);
    set("weapon_prop/armor", 11);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 16);
    set("weapon_prop/jingli", 16);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",7);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",6);
    set("wtypeF",7);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",8);
    

                set("skill", ([
                        "name": "leg",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 120,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 3);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_whip(133);
	setup();
}



#include "/obj/ritem/weaponzy.h";