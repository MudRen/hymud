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
	set_name("[1;32mÈçÊÇÎÒÎÅ[2;37;0m", ({ "moye sword", "sword" }));
	set_weight(14433);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("long", @LONG
[31mÄªĞ°·æÀûÎŞ±È£¬ÄÜ¿ªÌì±ÙµØ£¬µ´Ñı³ıÄ§£¡
[2;37;0mÕâÊÇÒ»°ÑÓÉÎŞ±È¼áÓ²µÄ[1;36mÍòÄêº®±ùÌú[2;37;0mÖÆ³É£¬ÖØ¶şÊ®°Ë½ï°ËÁ½ÁùÇ®µÄ[31mÄªĞ°Ö®½£[2;37;0m¡£
×ÛºÏÆÀ¼Û[35m»ÙÌìÃğµØ[2;37;0m ¿´ÆğÀ´ÎŞ±È·æÀû£¬¾ßÓĞ[1;35m¾øÊÀº±¼û[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;33m½ğ[2;37;0m:[1;33mÌìÊ¥[2;37;0m [36mÄ¾[2;37;0m:[1;32mÄ§Íõ[2;37;0m [32mË®[2;37;0m:[1;33mÌìÊ¥[2;37;0m [31m»ğ[2;37;0m:[1;31mÎŞË«[2;37;0m [1;37mÀ×[2;37;0m:[1;35m¾øÊÀ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;33mÃğÊÀ[2;37;0m ÌìÔ¨:[33mºÜ¸ß[2;37;0m ÌåÁé:[1;32mÄ§Íõ[2;37;0m °×Ê¯:[33mºÜ¸ß[2;37;0m ÉÁµç:[33mºÜ¸ß[2;37;0m 
ÖÜÌì:[31m¾«ÖÂ[2;37;0m ³¤Éú:[32m´Ö²Ú[2;37;0m ²»ÀÏ:[1;36mÍêÃÀ[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mÆÆÀÃÕ¾[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÖ¸·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "lyaxu");
		set("ownername", "ÆÆÀÃÕ¾");
		set("value", 36000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",43);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 41);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 43);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 94);
    
    set("weapon_prop/neili", 62);
    set("weapon_prop/qi", 38);
    set("weapon_prop/jing", 71);
    set("weapon_prop/jingli", 71);
    set("weapon_prop/damage", 0);

    set("wtypeA",10);
    set("wtypeB",9);
    set("wtypeC",10);
    set("wtypeD",12);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",11);
    set("wtypeH",0);
    set("wtypeI",9);
    set("wtypeJ",0);
    set("wtypeK",16);
    set("wtypeL",15);
    

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
	
	init_sword(968);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";