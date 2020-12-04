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
	set_name("[1;37m÷»×Ó[2;37;0m", ({ "taie sword", "sword" }));
	set_weight(22460);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("long", @LONG
[31mÌ«°¢µÛÍõÖ®±ø£¬³ÖÖ®ÄÜºÅÁîÌìÏÂ£¬ÄªÓĞ²»´Ó£¡
[2;37;0mÕâÊÇÒ»°ÑÓÉÎŞ±È¼áÓ²µÄ[1;36mÍòÄêº®±ùÌú[2;37;0mÖÆ³É£¬ÖØËÄÊ®ËÄ½ï¾ÅÁ½¶şÇ®µÄ[31mÌ«°¢Ö®½£[2;37;0m¡£
×ÛºÏÆÀ¼Û[35m»ÙÌìÃğµØ[2;37;0m ¿´ÆğÀ´ÎŞ±È·æÀû£¬¾ßÓĞ[1;36mÕ¶Ñı·üÄ§[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;36mÈË[2;37;0m:[1;33mÌìÊ¥[2;37;0m [36mÄ¾[2;37;0m:[1;32mÄ§Íõ[2;37;0m [31m»ğ[2;37;0m:[1;31m»ÙÌì[2;37;0m [33mÍÁ[2;37;0m:[1;31m´´ÊÀ[2;37;0m [1;35m·ç[2;37;0m:[1;31m´´ÊÀ[2;37;0m 
[1;37mÀ×[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;33mÃğÊÀ[2;37;0m ÌìÁé:[32m´Ö²Ú[2;37;0m ÌåÁé:[33mºÜ¸ß[2;37;0m °×Ê¯:[31m¾«ÖÂ[2;37;0m ³¤Éú:[1;32mÄ§Íõ[2;37;0m ²»ÀÏ:[1;36mÍêÃÀ[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mÎåÍò[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÖ¸·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "wuwan");
		set("ownername", "ÎåÍò");
		set("value", 36000);
		set("weapon_prop/intelligence",38);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 61);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 42);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 95);
    set("weapon_prop/jing", 70);
    set("weapon_prop/jingli", 70);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",9);
    set("wtypeC",0);
    set("wtypeD",15);
    set("wtypeE",14);
    set("wtypeF",14);
    set("wtypeG",8);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",10);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "finger",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 22);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_sword(628);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";