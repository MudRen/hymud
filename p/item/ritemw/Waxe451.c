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
	set_name("[31mÕ¿Â¬Ö®¸«[2;37;0m", ({ "zhanlu axe", "axe" }));
	set_weight(8186);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "±ú");
		set("long", @LONG
[31mÕ¿Â¬ÍşÁ¦¡¢·æÀû¡¢¼áÓ²¶¼¹Ú¾øµ±ÊÀ£¬ÄËÇ§¹ÅÉñ±ø£¡
[2;37;0mÕâÊÇÒ»±úÓÉÎŞ±È¼áÓ²µÄ[1;37mÈíÒø[2;37;0mÖÆ³É£¬ÖØÊ®Áù½ïÈıÁ½ÆßÇ®µÄ[31mÕ¿Â¬Ö®¸«[2;37;0m¡£
×ÛºÏÆÀ¼Û[35m»ÙÌìÃğµØ[2;37;0m ¿´ÆğÀ´ÎŞ±È·æÀû£¬¾ßÓĞ[1;32m¿ªÌìÅüµØ[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[32mË®[2;37;0m:[1;33mÌìÊ¥[2;37;0m [1;35m·ç[2;37;0m:[1;31m¿ªÔª[2;37;0m 
[1;37mÀ×[2;37;0m:[1;31mÎŞË«[2;37;0m [37mÌì[2;37;0m:[1;31mÎŞË«[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;33mÃğÊÀ[2;37;0m ÌìÔ¨:[33mºÜ¸ß[2;37;0m ÌìĞş:[33mºÜ¸ß[2;37;0m ÉÁµç:[35m±ê×¼[2;37;0m 
ÖÜÌì:[35m±ê×¼[2;37;0m ²»ÀÏ:[1;32mÄ§Íõ[2;37;0m 

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
		set("weapon_prop/dexerity",42);
		set("weapon_prop/constitution",40);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 53);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 50);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 90);
    set("weapon_prop/jingli", 90);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",10);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",13);
    set("wtypeG",12);
    set("wtypeH",0);
    set("wtypeI",12);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "parry",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 21);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_axe(793);
	setup();
}



#include "/obj/ritem/weaponzy.h";