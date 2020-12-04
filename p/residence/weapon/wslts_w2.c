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
	set_name("[1;32mÁúĞÇ[2;37;0m", ({ "zhendian throwing", "throwing" }));
	set_weight(386);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "Ö§");
		set("long", @LONG
[37mÕğµçÖ®°µÆ÷[2;37;0mÕâÊÇÒ»Ö§ÓÉ¼«Æä¼áÓ²µÄ[1;33m½ğÌú[2;37;0mÖÆ³É£¬ÖØÁã½ïÆßÁ½ÆßÇ®µÄ[37mÕğµçÖ®°µÆ÷[2;37;0m¡£
×ÛºÏÆÀ¼Û[37m¾øÊÀÎŞË«[2;37;0m ¿´ÆğÀ´¼«Æä·æÀû£¬¾ßÓĞ[31mÎŞÓëÂ×±È[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;36mÈË[2;37;0m:[33mºÜ¸ß[2;37;0m [32mË®[2;37;0m:[1;35m¾øÊÀ[2;37;0m [33mÍÁ[2;37;0m:[1;36mÍêÃÀ[2;37;0m [1;35m·ç[2;37;0m:[1;35m¾øÊÀ[2;37;0m 

ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;31mÎŞË«[2;37;0m ÇÉÖÆ:[33mºÜ¸ß[2;37;0m 
°×Ê¯:[33mºÜ¸ß[2;37;0m ÖÜÌì:[35m±ê×¼[2;37;0m ³¤Éú:[34mÏ¸Ëé[2;37;0m ÍşÁ¦:[34mÏ¸Ëé[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mÄªµÈÏĞ[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÄÚ¹¦[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "wslts");
		set("ownername", "ÄªµÈÏĞ");
		set("value", 16000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 46);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 45);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 55);
    set("weapon_prop/qi", 20);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 26);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",11);
    set("wtypeD",0);
    set("wtypeE",7);
    set("wtypeF",11);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",4);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "force",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 12);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	set_amount(99);
	init_throwing(557);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";