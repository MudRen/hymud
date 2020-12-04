// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit BLADE;

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
	set_name("[37mºìÓñÖ®µ¶[2;37;0m", ({ "hongyu blade", "blade" }));
	set_weight(13975);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "±ú");
		set("long", @LONG
[37mºìÓñÖ®µ¶[2;37;0mÕâÊÇÒ»±úÓÉÎŞ±È¼áÓ²µÄ[1;33m½ğÌú[2;37;0mÖÆ³É£¬ÖØ¶şÊ®Æß½ï¾ÅÁ½ÎåÇ®µÄ[37mºìÓñÖ®µ¶[2;37;0m¡£
×ÛºÏÆÀ¼Û[37m¾øÊÀÎŞË«[2;37;0m ¿´ÆğÀ´ÎŞ±È·æÀû£¬¾ßÓĞ[1;35m¾øÊÀº±¼û[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;33m½ğ[2;37;0m:[1;33mÌìÊ¥[2;37;0m [36mÄ¾[2;37;0m:[1;33mÌìÊ¥[2;37;0m [32mË®[2;37;0m:[35m±ê×¼[2;37;0m [31m»ğ[2;37;0m:[1;36mÍêÃÀ[2;37;0m [1;35m·ç[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m 
[1;34mµç[2;37;0m:[1;36mÍêÃÀ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;31mÎŞË«[2;37;0m ÌåÁé:[32m´Ö²Ú[2;37;0m °×Ê¯:[35m±ê×¼[2;37;0m ×ÏÊ¯:[32m´Ö²Ú[2;37;0m ÉÁµç:[34mÏ¸Ëé[2;37;0m 
ÖÜÌì:[33mºÜ¸ß[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32m·½·½[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÕÆ·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "fend");
		set("ownername", "·½·½");
		set("value", 16000);
		set("weapon_prop/intelligence",48);
		set("weapon_prop/strength",40);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 54);
    set("weapon_prop/parry", 37);
    set("weapon_prop/attack", 21);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 38);
    
    set("weapon_prop/neili", 43);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",10);
    set("wtypeB",10);
    set("wtypeC",5);
    set("wtypeD",7);
    set("wtypeE",0);
    set("wtypeF",8);
    set("wtypeG",0);
    set("wtypeH",7);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",5);
    

                set("skill", ([
                        "name": "strike",
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
	
	init_blade(1094);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";