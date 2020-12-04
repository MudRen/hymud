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
	set_name("[1;33mÔÂÃ¢[2;37;0m", ({ "fengyun sword", "sword" }));
	set_weight(10056);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("long", @LONG
[1;35mËùÎ½·çÔÆ¼Ê»á£¬ÌìµØ±äÉ«£¡ÕÌ´ËĞĞÇ§Àï£¬ÀÏÄ§Ğ¡³ó£¬Æñ¿°Ò»»÷£¡
[2;37;0mÕâÊÇÒ»°ÑÓÉÎŞ±È¼áÓ²µÄ[37mĞşÌú[2;37;0mÖÆ³É£¬ÖØ¶şÊ®½ïÒ»Á½Ò»Ç®µÄ[1;35m·çÔÆÖ®½£[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´ÎŞ±È·æÀû£¬¾ßÓĞ[1;33m¾ÙÊÀÎŞÆ¥[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;36mÈË[2;37;0m:[1;35m¾øÊÀ[2;37;0m [1;31mÄ§[2;37;0m:[1;31m´´ÊÀ[2;37;0m [32mË®[2;37;0m:[1;32mÄ§Íõ[2;37;0m [31m»ğ[2;37;0m:[1;31m¿ªÔª[2;37;0m [33mÍÁ[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m [1;35m·ç[2;37;0m:[1;31m´´ÊÀ[2;37;0m 

ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;33mÃğÊÀ[2;37;0m ÇÉÖÆ:[34mÏ¸Ëé[2;37;0m 
°×Ê¯:[32m´Ö²Ú[2;37;0m ×ÏÊ¯:[33mºÜ¸ß[2;37;0m ³¤Éú:[31m¾«ÖÂ[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32m»¨ÎŞÀâ[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÕÈ·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "enjoy");
		set("ownername", "»¨ÎŞÀâ");
		set("value", 25000);
		set("weapon_prop/intelligence",56);
		set("weapon_prop/strength",48);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",40);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 30);
    set("weapon_prop/parry", 48);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 56);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 56);
    set("weapon_prop/qi", 67);
    set("weapon_prop/jing", 40);
    set("weapon_prop/jingli", 56);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",9);
    set("wtypeD",13);
    set("wtypeE",8);
    set("wtypeF",14);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",8);
    set("wtypeJ",7);
    set("wtypeK",11);
    set("wtypeL",14);
    

                set("skill", ([
                        "name": "staff",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 18);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_sword(1365);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";