// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit DAGGER;

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
	set_name("[1;37mÆß×Ú×ï[2;37;0m", ({ "taiji dagger", "dagger" }));
	set_weight(270);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "Ö§");
		set("long", @LONG
[1;33mÌ«¼«Õß£¬ÎŞ¼«¶øÉú£¬ÒõÑôÖ®Ä¸Ò²¡£¶¯Ö®Ôò·Ö£¬¾²Ö®ÔòºÏ¡£ÎŞ¹ı²»¼°£¬ËæÇú¾ÍÉì¡£
ÈË¸ÕÎÒÈáÎ½Ö®×ß£¬ÎÒË³ÈË±³Î½Ö®Õ³¡£¶¯¼±Ôò¼±Ó¦£¬¶¯»ºÔò»ºËæ¡£Ëä±ä»¯Íò¶Ë£¬¶ø
ÀíÎªÒ»¹á£¡
[2;37;0mÕâÊÇÒ»Ö§ÓÉÎŞ±È¼áÓ²µÄ[31mÍòÄêÉñÌú[2;37;0mÖÆ³É£¬ÖØÁã½ïÎåÁ½ËÄÇ®µÄ[1;33mÌ«¼«Ö®°µÆ÷[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´ÎŞ±È·æÀû£¬¾ßÓĞ[1;33m¾ÙÊÀÎŞÆ¥[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;36mÈË[2;37;0m:[1;32mÄ§Íõ[2;37;0m [1;33m½ğ[2;37;0m:[1;31m´´ÊÀ[2;37;0m [36mÄ¾[2;37;0m:[1;31m¿ªÔª[2;37;0m [32mË®[2;37;0m:[1;35m¾øÊÀ[2;37;0m [31m»ğ[2;37;0m:[31m¾«ÖÂ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;31m»ÙÌì[2;37;0m ÌåÁé:[35m±ê×¼[2;37;0m ÖÜÌì:[31m¾«ÖÂ[2;37;0m ³¤Éú:[1;36mÍêÃÀ[2;37;0m ²»ÀÏ:[33mºÜ¸ß[2;37;0m ÍşÁ¦:[31m¾«ÖÂ[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mµØÍ¼Ò»ºÅ[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32m½£·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "maper");
		set("ownername", "µØÍ¼Ò»ºÅ");
		set("value", 25000);
		set("weapon_prop/intelligence",56);
		set("weapon_prop/strength",48);
		set("weapon_prop/karey",48);
		set("weapon_prop/percao",56);
		set("weapon_prop/dexerity",56);
		set("weapon_prop/constitution",48);
    set("weapon_prop/dodge", 48);
    set("weapon_prop/parry", 56);
    set("weapon_prop/attack", 56);
    set("weapon_prop/armor", 56);
    set("weapon_prop/defense", 55);
    
    set("weapon_prop/neili", 68);
    set("weapon_prop/qi", 74);
    set("weapon_prop/jing", 46);
    set("weapon_prop/jingli", 46);
    set("weapon_prop/damage", 64);

    set("wtypeA",14);
    set("wtypeB",13);
    set("wtypeC",11);
    set("wtypeD",6);
    set("wtypeE",6);
    set("wtypeF",6);
    set("wtypeG",6);
    set("wtypeH",6);
    set("wtypeI",6);
    set("wtypeJ",0);
    set("wtypeK",9);
    set("wtypeL",7);
    

                set("skill", ([
                        "name": "sword",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 15);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	//set_amount(99);
	init_dagger(976);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";