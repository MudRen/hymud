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
	set_name("[1;37m³¤Éú½£[2;37;0m", ({ "fengyun sword", "sword" }));
	set_weight(15892);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("long", @LONG
[1;35mËùÎ½·çÔÆ¼Ê»á£¬ÌìµØ±äÉ«£¡ÕÌ´ËĞĞÇ§Àï£¬ÀÏÄ§Ğ¡³ó£¬Æñ¿°Ò»»÷£¡
[2;37;0mÕâÊÇÒ»°ÑÓÉÎŞ±È¼áÓ²µÄ[37mĞşÌú[2;37;0mÖÆ³É£¬ÖØÈıÊ®Ò»½ïÆßÁ½°ËÇ®µÄ[1;35m·çÔÆÖ®½£[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´ÎŞ±È·æÀû£¬¾ßÓĞ[1;31m¿ªÔª´´ÊÀ[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;31mÄ§[2;37;0m:[1;31m¿ªÔª[2;37;0m [31m»ğ[2;37;0m:[1;31m´´ÊÀ[2;37;0m [1;35m·ç[2;37;0m:[1;35m¾øÊÀ[2;37;0m 
[1;37mÀ×[2;37;0m:[31m¾«ÖÂ[2;37;0m [1;34mµç[2;37;0m:[1;36mÍêÃÀ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;31m»ÙÌì[2;37;0m ÌìÓî:[34mÏ¸Ëé[2;37;0m ¸£Ô´:[32m´Ö²Ú[2;37;0m 
ÌìĞş:[34mÏ¸Ëé[2;37;0m ÌåÁé:[32m´Ö²Ú[2;37;0m ³¤Éú:[33mºÜ¸ß[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32m¶ÎÒ©Ê¦[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32m¸«·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "yellow");
		set("ownername", "¶ÎÒ©Ê¦");
		set("value", 25000);
		set("weapon_prop/intelligence",56);
		set("weapon_prop/strength",56);
		set("weapon_prop/karey",56);
		set("weapon_prop/percao",56);
		set("weapon_prop/dexerity",48);
		set("weapon_prop/constitution",40);
    set("weapon_prop/dodge", 24);
    set("weapon_prop/parry", 56);
    set("weapon_prop/attack", 56);
    set("weapon_prop/armor", 56);
    set("weapon_prop/defense", 56);
    
    set("weapon_prop/neili", 56);
    set("weapon_prop/qi", 56);
    set("weapon_prop/jing", 56);
    set("weapon_prop/jingli", 56);
    set("weapon_prop/damage", 48);

    set("wtypeA",5);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",14);
    set("wtypeE",0);
    set("wtypeF",11);
    set("wtypeG",6);
    set("wtypeH",7);
    set("wtypeI",6);
    set("wtypeJ",0);
    set("wtypeK",6);
    set("wtypeL",13);
    

                set("skill", ([
                        "name": "axe",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 15);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_sword(3810);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";