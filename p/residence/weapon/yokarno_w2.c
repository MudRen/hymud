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
	set_name("[1;31mò¯³ÏÖ®ÈĞ[2;37;0m", ({ "bad blade", "blade" }));
	set_weight(3508);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "±ú");
		set("long", @LONG
ÌúÖ®µ¶[2;37;0mÕâÊÇÒ»±úÓÉ·Ç³£¼áÓ²µÄ[32mÇàÍ­[2;37;0mÖÆ³É£¬ÖØÆß½ïÁãÁ½Ò»Ç®µÄ[1;31mÌúÖ®µ¶[2;37;0m¡£
×ÛºÏÆÀ¼Û[32m¾«ÖÂÏ¸ÃÀ[2;37;0m ¿´ÆğÀ´·Ç³£·æÀû£¬¾ßÓĞ[35m¼«Æä¿ÉÅÂ[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[33mÍÁ[2;37;0m:[33mºÜ¸ß[2;37;0m [1;34mµç[2;37;0m:[35m±ê×¼[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[32m´Ö²Ú[2;37;0m °×Ê¯:[33mÒ»°ã[2;37;0m ×ÏÊ¯:[32m¼«²î[2;37;0m ÖÜÌì:[33mÒ»°ã[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mÔÆÔÂôá[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÕÆ·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "yokarno");
		set("ownername", "ÔÆÔÂôá");
		set("value", 2000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 8);
    set("weapon_prop/parry", 3);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 7);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",4);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",5);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "strike",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 50,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 3);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_blade(333);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";