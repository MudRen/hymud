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
	set_name("[37m³àÓñÖ®½£[2;37;0m", ({ "chiyu sword", "sword" }));
	set_weight(3481);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("long", @LONG
[37m³àÓñÖ®½£[2;37;0mÕâÊÇÒ»°ÑÓÉÎŞ±È¼áÓ²µÄ[1;33m½ğÌú[2;37;0mÖÆ³É£¬ÖØÁù½ï¾ÅÁ½ÁùÇ®µÄ[37m³àÓñÖ®½£[2;37;0m¡£
×ÛºÏÆÀ¼Û[37m¾øÊÀÎŞË«[2;37;0m ¿´ÆğÀ´ÎŞ±È·æÀû£¬¾ßÓĞ[1;35m¾øÊÀº±¼û[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[40mµØ[2;37;0m:[1;32mÄ§Íõ[2;37;0m [1;31mÄ§[2;37;0m:[1;33mÌìÊ¥[2;37;0m [1;33m½ğ[2;37;0m:[31m¾«ÖÂ[2;37;0m [31m»ğ[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;31mÎŞË«[2;37;0m ÌìÁé:[36m²»´í[2;37;0m ÌåÁé:[32m´Ö²Ú[2;37;0m °×Ê¯:[36m²»´í[2;37;0m ÉÁµç:[34mÏ¸Ëé[2;37;0m 

ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mĞ¡Ñ©¶ù[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32m´¸·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "xiaoxueer");
		set("ownername", "Ğ¡Ñ©¶ù");
		set("value", 16000);
		set("weapon_prop/intelligence",17);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 18);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 20);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 39);
    
    set("weapon_prop/neili", 40);
    set("weapon_prop/qi", 48);
    set("weapon_prop/jing", 48);
    set("weapon_prop/jingli", 40);
    set("weapon_prop/damage", 0);

    set("wtypeA",6);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",8);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",9);
    set("wtypeK",0);
    set("wtypeL",10);
    

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
    set("sharpness", 15);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_sword(1229);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";