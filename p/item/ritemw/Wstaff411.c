// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit STAFF;

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
	set_name("[1;35mĞùÔ¯Ö®ÕÈ[2;37;0m", ({ "xuanyuan staff", "staff" }));
	set_weight(12760);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "¸ù");
		set("long", @LONG
[1;35mÎôÈÕ»ÆµÛ³Ö´ËÎïÁ¢ÓÚÖ¸ÄÏ³µÉÏ£¬ÇıÃÔÎí£¬É¨Òõö²£¬ÂÊÓ¦Áúºµ÷É£¬Óù°ÙÊŞ¶øÕ½ò¿ÓÈ£¡
[2;37;0mÕâÊÇÒ»¸ùÓÉÎŞ±È¼áÓ²µÄ[31mÁ÷»¨Ê¯[2;37;0mÖÆ³É£¬ÖØ¶şÊ®Îå½ïÎåÁ½¶şÇ®µÄ[1;35mĞùÔ¯Ö®ÕÈ[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´ÎŞ±È·æÀû£¬¾ßÓĞ[1;31mÌìÏÂÎŞË«[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[36mÄ¾[2;37;0m:[1;31m´´ÊÀ[2;37;0m [37mÌì[2;37;0m:[1;32mÄ§Íõ[2;37;0m [1;31mÄ§[2;37;0m:[1;31m´´ÊÀ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;33mÃğÊÀ[2;37;0m ¸£Ô´:[32m´Ö²Ú[2;37;0m 
¾ø´ú:[32m´Ö²Ú[2;37;0m ÇÉÖÆ:[31m¾«ÖÂ[2;37;0m 
²»ÀÏ:[33mºÜ¸ß[2;37;0m 

LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 25000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",36);
		set("weapon_prop/percao",36);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 62);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 41);
    set("weapon_prop/jingli", 41);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",14);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",9);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",14);
    

                set("skill", ([
                        "name": "parry",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 19);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_staff(1025);
	setup();
}



#include "/obj/ritem/weaponzy.h";