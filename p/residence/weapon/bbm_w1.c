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
	set_name("[37mÁ÷ÅÎÖ®½£[2;37;0m", ({ "good sword", "sword" }));
	set_weight(4712);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("long", @LONG
Á÷ÅÎÖ®½£[2;37;0mÕâÊÇÒ»°ÑÓÉÎŞ±È¼áÓ²µÄ[31mÁ÷»¨Ê¯[2;37;0mÖÆ³É£¬ÖØ¾Å½ïËÄÁ½¶şÇ®µÄ[37mÁ÷ÅÎÖ®½£[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;34m¾ÙÊÀº±¼û[2;37;0m ¿´ÆğÀ´ÎŞ±È·æÀû£¬¾ßÓĞ[31mÎŞÓëÂ×±È[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;33m½ğ[2;37;0m:[32m´Ö²Ú[2;37;0m [36mÄ¾[2;37;0m:[33mºÜ¸ß[2;37;0m [32mË®[2;37;0m:[1;32mÄ§Íõ[2;37;0m [31m»ğ[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m [1;35m·ç[2;37;0m:[1;33mÌìÊ¥[2;37;0m 

ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;33mÌìÊ¥[2;37;0m ÌìÔ¨:[36m²»´í[2;37;0m ÌåÁé:[34mÏ¸Ëé[2;37;0m °×Ê¯:[32m´Ö²Ú[2;37;0m ×ÏÊ¯:[36m²»´í[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mĞÇÒş[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÕĞ¼Ü[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "bbm");
		set("ownername", "ĞÇÒş");
		set("value", 9000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",24);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",13);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 30);
    set("weapon_prop/parry", 18);
    set("weapon_prop/attack", 32);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 23);
    
    set("weapon_prop/neili", 24);
    set("weapon_prop/qi", 24);
    set("weapon_prop/jing", 16);
    set("weapon_prop/jingli", 40);
    set("weapon_prop/damage", 0);

    set("wtypeA",3);
    set("wtypeB",4);
    set("wtypeC",9);
    set("wtypeD",8);
    set("wtypeE",0);
    set("wtypeF",10);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",2);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "parry",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 240,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 10);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_sword(604);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";