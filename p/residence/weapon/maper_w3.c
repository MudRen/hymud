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
	set_name("[33m·çÓêÀ×µç[2;37;0m", ({ "wulong sword", "sword" }));
	set_weight(4316);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("long", @LONG
[35mÎåÁúÖ®½£[2;37;0mÕâÊÇÒ»°ÑÓÉ¼«Æä¼áÓ²µÄ[1;37mÈíÒø[2;37;0mÖÆ³É£¬ÖØ°Ë½ïÁùÁ½ÈıÇ®µÄ[35mÎåÁúÖ®½£[2;37;0m¡£
×ÛºÏÆÀ¼Û[37m¾øÊÀÎŞË«[2;37;0m ¿´ÆğÀ´¼«Æä·æÀû£¬¾ßÓĞ[31mÎŞÓëÂ×±È[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;33m½ğ[2;37;0m:[1;36mÍêÃÀ[2;37;0m [36mÄ¾[2;37;0m:[1;36mÍêÃÀ[2;37;0m [33mÍÁ[2;37;0m:[31m¾«ÖÂ[2;37;0m [1;35m·ç[2;37;0m:[31m¾«ÖÂ[2;37;0m 

ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;31m¿ªÔª[2;37;0m ¸£Ô´:[34mÏ¸Ëé[2;37;0m 
ÌìÔ¨:[34mÏ¸Ëé[2;37;0m ÌåÁé:[33mºÜ¸ß[2;37;0m °×Ê¯:[34mÏ¸Ëé[2;37;0m ÉÁµç:[36m²»´í[2;37;0m 

ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mµØÍ¼Ò»ºÅ[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32m¹÷·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

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
		set("value", 16000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",22);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",27);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 23);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 16);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 43);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",7);
    set("wtypeB",7);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",6);
    set("wtypeF",6);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "club",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 13);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_sword(463);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";