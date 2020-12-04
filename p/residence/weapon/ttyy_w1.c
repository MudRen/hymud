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
	set_name("[1;31m÷è÷ëÖ®½£[2;37;0m", ({ "qilin sword", "sword" }));
	set_weight(2634);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("long", @LONG
[1;31m÷è÷ëÖ®½£[2;37;0mÕâÊÇÒ»°ÑÓÉ¼«Îª¼áÓ²µÄ[1;33m½ğÌú[2;37;0mÖÆ³É£¬ÖØÎå½ï¶şÁ½ÁùÇ®µÄ[1;31m÷è÷ëÖ®½£[2;37;0m¡£
×ÛºÏÆÀ¼Û[37m¾øÊÀÎŞË«[2;37;0m ¿´ÆğÀ´¼«Îª·æÀû£¬¾ßÓĞ[1;33m¾ÙÊÀÎŞÆ¥[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;35m·ç[2;37;0m:[33mºÜ¸ß[2;37;0m 
[1;37mÀ×[2;37;0m:[1;35m¾øÊÀ[2;37;0m [1;34mµç[2;37;0m:[1;32mÄ§Íõ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;31mÎŞË«[2;37;0m ÌåÁé:[32m´Ö²Ú[2;37;0m ÉÁµç:[35m±ê×¼[2;37;0m 
ÖÜÌì:[36m²»´í[2;37;0m ³¤Éú:[35m±ê×¼[2;37;0m ÍşÁ¦:[32m´Ö²Ú[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mÍÅÍÅÔ²Ô²[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32m½£·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "ttyy");
		set("ownername", "ÍÅÍÅÔ²Ô²");
		set("value", 16000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 54);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 36);
    
    set("weapon_prop/neili", 19);
    set("weapon_prop/qi", 50);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 36);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",4);
    set("wtypeG",11);
    set("wtypeH",9);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",3);
    

                set("skill", ([
                        "name": "sword",
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
	
	init_sword(908);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";