// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit THROWING;

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
	set_name("[1;33mÌ«¼«Ö®°µÆ÷[2;37;0m¡ï", ({ "taiji throwing", "throwing" }));
	set_weight(294);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "Ö§");
		set("long", @LONG
[1;33mÌ«¼«Õß£¬ÎŞ¼«¶øÉú£¬ÒõÑôÖ®Ä¸Ò²¡£¶¯Ö®Ôò·Ö£¬¾²Ö®ÔòºÏ¡£ÎŞ¹ı²»¼°£¬ËæÇú¾ÍÉì¡£
ÈË¸ÕÎÒÈáÎ½Ö®×ß£¬ÎÒË³ÈË±³Î½Ö®Õ³¡£¶¯¼±Ôò¼±Ó¦£¬¶¯»ºÔò»ºËæ¡£Ëä±ä»¯Íò¶Ë£¬¶ø
ÀíÎªÒ»¹á£¡
[2;37;0mÕâÊÇÒ»Ö§ÓÉÎŞ±È¼áÓ²µÄ[31mÁ÷»¨Ê¯[2;37;0mÖÆ³É£¬ÖØÁã½ïÎåÁ½°ËÇ®µÄ[1;33mÌ«¼«Ö®°µÆ÷[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´ÎŞ±È·æÀû£¬¾ßÓĞ[31mÎŞÓëÂ×±È[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[36mÄ¾[2;37;0m:[1;31mÎŞË«[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;33mÃğÊÀ[2;37;0m ÌìÔ¨:[32m´Ö²Ú[2;37;0m ÌìĞş:[32m´Ö²Ú[2;37;0m ÉÁµç:[31m¾«ÖÂ[2;37;0m 
²»ÀÏ:[34mÏ¸Ëé[2;37;0m ÍşÁ¦:[35m±ê×¼[2;37;0m 

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
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",34);
		set("weapon_prop/constitution",35);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 61);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 26);
    set("weapon_prop/jingli", 26);
    set("weapon_prop/damage", 52);

    set("wtypeA",0);
    set("wtypeB",12);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "blade",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 17);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	set_amount(1);
	init_throwing(530);
	setup();
}



#include "/obj/ritem/weaponzy.h";