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
	set_name("[1;36m°×º×[2;37;0m", ({ "bad sword", "sword" }));
	set_weight(2466);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("long", @LONG
ÌúÖ®½£[2;37;0mÕâÊÇÒ»°ÑÓÉÏàµ±¼áÓ²µÄ[32mÇàÍ­[2;37;0mÖÆ³É£¬ÖØËÄ½ï¾ÅÁ½ÈıÇ®µÄ[1;36mÌúÖ®½£[2;37;0m¡£
×ÛºÏÆÀ¼Û[32m¾«ÖÂÏ¸ÃÀ[2;37;0m ¿´ÆğÀ´Ïàµ±·æÀû£¬¾ßÓĞ[36m²»Ğ¡[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[36mÄ¾[2;37;0m:[35m±ê×¼[2;37;0m [1;34mµç[2;37;0m:[33mºÜ¸ß[2;37;0m [37mÌì[2;37;0m:[32m´Ö²Ú[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[33mºÜ¸ß[2;37;0m °×Ê¯:[32m¼«²î[2;37;0m ÉÁµç:[33mÒ»°ã[2;37;0m 
²»ÀÏ:[32m¼«²î[2;37;0m ÍşÁ¦:[32m¼«²î[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32m´«Õæ»úÒ»ºÅ[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÕÈ·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "faxone");
		set("ownername", "´«Õæ»úÒ»ºÅ");
		set("value", 2000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 4);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 7);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 2);
    set("weapon_prop/jingli", 2);
    set("weapon_prop/damage", 5);

    set("wtypeA",0);
    set("wtypeB",5);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",4);
    set("wtypeI",3);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "staff",
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
	
	init_sword(73);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";