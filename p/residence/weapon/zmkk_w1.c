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
	set_name("[1;36mËª»ğÖ®½£[2;37;0m", ({ "bad sword", "sword" }));
	set_weight(4786);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("long", @LONG
ÖñÖ®½£[2;37;0mÕâÊÇÒ»°ÑÓÉ»¹Ëã¼áÓ²µÄ[32mÇàÍ­[2;37;0mÖÆ³É£¬ÖØ¾Å½ïÎåÁ½ÆßÇ®µÄ[1;36mÖñÖ®½£[2;37;0m¡£
×ÛºÏÆÀ¼Û[32m¾«ÖÂÏ¸ÃÀ[2;37;0m ¿´ÆğÀ´»¹Ëã·æÀû£¬¾ßÓĞ[34m²»´í[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[32mË®[2;37;0m:[34mÏ¸Ëé[2;37;0m [33mÍÁ[2;37;0m:[33mºÜ¸ß[2;37;0m [1;34mµç[2;37;0m:[34mÏ¸Ëé[2;37;0m [40mµØ[2;37;0m:[36m²»´í[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[33mºÜ¸ß[2;37;0m ¾ø´ú:[32m¼«²î[2;37;0m ÌìĞş:[33mÒ»°ã[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mÔÆÔÂÎè[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32m×¦·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "zmkk");
		set("ownername", "ÔÆÔÂÎè");
		set("value", 2000);
		set("weapon_prop/intelligence",72);
		set("weapon_prop/strength",72);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",5);
		set("weapon_prop/dexerity",72);
		set("weapon_prop/constitution",72);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 72);
    set("weapon_prop/qi", 72);
    set("weapon_prop/jing", 72);
    set("weapon_prop/jingli", 72);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",2);
    set("wtypeD",9);
    set("wtypeE",4);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",2);
    set("wtypeI",0);
    set("wtypeJ",9);
    set("wtypeK",9);
    set("wtypeL",9);
    

                set("skill", ([
                        "name": "claw",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 50,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 4);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_sword(408);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";