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
	set_name("[33mÑş³ØÖ®½£[2;37;0m", ({ "yaochi sword", "sword" }));
	set_weight(2466);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("long", @LONG
[33mÑş³ØÖ®½£[2;37;0mÕâÊÇÒ»°ÑÓÉ¾ø¶Ô¼áÓ²µÄ[1;33m½ğÌú[2;37;0mÖÆ³É£¬ÖØËÄ½ï¾ÅÁ½ÈıÇ®µÄ[33mÑş³ØÖ®½£[2;37;0m¡£
×ÛºÏÆÀ¼Û[37m¾øÊÀÎŞË«[2;37;0m ¿´ÆğÀ´¾ø¶Ô·æÀû£¬¾ßÓĞ[1;34mÒĞÌìÍÀÁú[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[32mË®[2;37;0m:[33mºÜ¸ß[2;37;0m [33mÍÁ[2;37;0m:[1;31mÎŞË«[2;37;0m [1;35m·ç[2;37;0m:[35m±ê×¼[2;37;0m 
[1;37mÀ×[2;37;0m:[1;31mÎŞË«[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;31mÎŞË«[2;37;0m ÌìÁé:[36m²»´í[2;37;0m ¸£Ô´:[36m²»´í[2;37;0m 
¾ø´ú:[34mÏ¸Ëé[2;37;0m ÌåÁé:[35m±ê×¼[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32m¶Î×ÓºÛ[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32m´¸·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "dzh");
		set("ownername", "¶Î×ÓºÛ");
		set("value", 16000);
		set("weapon_prop/intelligence",16);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",16);
		set("weapon_prop/percao",23);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 51);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",4);
    set("wtypeD",0);
    set("wtypeE",12);
    set("wtypeF",5);
    set("wtypeG",12);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "hammer",
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
	
	init_sword(778);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";