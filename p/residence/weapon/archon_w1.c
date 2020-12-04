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
	set_name("[33m½ğ¹âÖ®½£[2;37;0m", ({ "jinguang sword", "sword" }));
	set_weight(2933);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("long", @LONG
[33m½ğ¹âÖ®½£[2;37;0mÕâÊÇÒ»°ÑÓÉÎŞ±È¼áÓ²µÄ[1;37mÈíÒø[2;37;0mÖÆ³É£¬ÖØÎå½ï°ËÁ½ÁùÇ®µÄ[33m½ğ¹âÖ®½£[2;37;0m¡£
×ÛºÏÆÀ¼Û[37m¾øÊÀÎŞË«[2;37;0m ¿´ÆğÀ´ÎŞ±È·æÀû£¬¾ßÓĞ[1;33m¾ÙÊÀÎŞÆ¥[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[37mÌì[2;37;0m:[33mºÜ¸ß[2;37;0m [40mµØ[2;37;0m:[33mºÜ¸ß[2;37;0m [36mÄ¾[2;37;0m:[35m±ê×¼[2;37;0m [32mË®[2;37;0m:[1;32mÄ§Íõ[2;37;0m [33mÍÁ[2;37;0m:[1;31mÎŞË«[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;31mÎŞË«[2;37;0m ÇÉÖÆ:[32m´Ö²Ú[2;37;0m 
ÌåÁé:[33mºÜ¸ß[2;37;0m ×ÏÊ¯:[33mºÜ¸ß[2;37;0m ÉÁµç:[33mºÜ¸ß[2;37;0m 
ÖÜÌì:[36m²»´í[2;37;0m ³¤Éú:[34mÏ¸Ëé[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mÊ¥ÌÃ[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÄÚ¹¦[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "archon");
		set("ownername", "Ê¥ÌÃ");
		set("value", 16000);
		set("weapon_prop/intelligence",24);
		set("weapon_prop/strength",32);
		set("weapon_prop/karey",40);
		set("weapon_prop/percao",24);
		set("weapon_prop/dexerity",24);
		set("weapon_prop/constitution",24);
    set("weapon_prop/dodge", 24);
    set("weapon_prop/parry", 43);
    set("weapon_prop/attack", 49);
    set("weapon_prop/armor", 36);
    set("weapon_prop/defense", 48);
    
    set("weapon_prop/neili", 40);
    set("weapon_prop/qi", 48);
    set("weapon_prop/jing", 48);
    set("weapon_prop/jingli", 40);
    set("weapon_prop/damage", 0);

    set("wtypeA",3);
    set("wtypeB",5);
    set("wtypeC",2);
    set("wtypeD",4);
    set("wtypeE",12);
    set("wtypeF",0);
    set("wtypeG",4);
    set("wtypeH",4);
    set("wtypeI",4);
    set("wtypeJ",4);
    set("wtypeK",2);
    set("wtypeL",2);
    

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
	
	init_sword(1116);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";