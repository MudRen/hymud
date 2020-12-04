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
	set_name("[1;31mĞùÔ¯½£[2;37;0m", ({ "joeywus sword", "sword" }));
	set_weight(14463);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("long", @LONG
[1;34mÔÚÎ÷·½²éÀíÂüÍ³ÖÎµÄÊ±´ú£¬×î¼òÆÓµÄ½£Ò²ÄÜÖµÈıÍ·Ä¸Å£µÄ¼ÛÇ®¡£¶ø²éÀí´óµÛ×Ô¼ºµÄÄÇ°Ñ´«ÆæÊ½
µÄÉñ±ø¡°ÇÇÒÀÎÚË¹¡±¾İËµÊÇ°ëÈË°ëÉñµÄ¡°Î¤À¼Ìú½³¡±ËùÔì£¬ÄËµ±ÊÀ½çÉñ±ø£¡
[2;37;0mÕâÊÇÒ»°ÑÓÉÎŞ±È¼áÓ²µÄ[37mĞşÌú[2;37;0mÖÆ³É£¬ÖØ¶şÊ®°Ë½ï¾ÅÁ½¶şÇ®µÄ[1;34mÇÇÒÀÎÚË¹Ö®½£[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´ÎŞ±È·æÀû£¬¾ßÓĞ[1;33m¾ÙÊÀÎŞÆ¥[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;33m½ğ[2;37;0m:[1;31mÎŞË«[2;37;0m [36mÄ¾[2;37;0m:[35m±ê×¼[2;37;0m [32mË®[2;37;0m:[1;35m¾øÊÀ[2;37;0m [1;34mµç[2;37;0m:[1;33mÌìÊ¥[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;33mÃğÊÀ[2;37;0m ÇÉÖÆ:[1;36mÍêÃÀ[2;37;0m 
ÌåÁé:[31m¾«ÖÂ[2;37;0m °×Ê¯:[1;36mÍêÃÀ[2;37;0m ³¤Éú:[33mºÜ¸ß[2;37;0m ²»ÀÏ:[31m¾«ÖÂ[2;37;0m ÍşÁ¦:[32m´Ö²Ú[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32m¿´¿´[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÕÆ·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "beg");
		set("ownername", "¿´¿´");
		set("value", 25000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",32);
		set("weapon_prop/karey",40);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",40);
		set("weapon_prop/constitution",40);
    set("weapon_prop/dodge", 71);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 71);
    set("weapon_prop/defense", 63);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 40);
    set("weapon_prop/jing", 68);
    set("weapon_prop/jingli", 68);
    set("weapon_prop/damage", 33);

    set("wtypeA",12);
    set("wtypeB",5);
    set("wtypeC",11);
    set("wtypeD",3);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",10);
    set("wtypeI",8);
    set("wtypeJ",0);
    set("wtypeK",4);
    set("wtypeL",3);
    

                set("skill", ([
                        "name": "strike",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 16);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_sword(967);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";