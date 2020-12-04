#include <ansi.h> 
#include <armor.h>

inherit HANDS;

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

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	      set_name("[35mÈıÖ»ÊÖ[2;37;0m", ({ "sanqing hands", "hands" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¸±");
		set("long", @LONG
[1;36m´óµÀÎŞÃû£¬¾ÛÆø³ÉĞÎ£¬¹¦²ÎÔì»¯£¬Ò»ÊÇÈıÇå£¡Õâ±ãÊÇ¡°ÀÏ×ÓÒ»î¸»¯ÈıÇå¡£¡±
[2;37;0mÕâÊÇÒ»¸±ÓÉÎŞ±È¼áÓ²µÄ[37mĞşÌú[2;37;0m¼ÓÉÏ[37mÌì²ÏË¿[2;37;0mÖÆ³É£¬ÖØÁù½ïÁãÁ½¶şÇ®µÄ[1;36mÈıÇåÖ®ÊÖÌ×[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[34m²»´í[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[31m»ğ[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m [33mÍÁ[2;37;0m:[1;33mÌìÊ¥[2;37;0m [1;35m·ç[2;37;0m:[1;31m´´ÊÀ[2;37;0m 
[1;37mÀ×[2;37;0m:[1;31m´´ÊÀ[2;37;0m [1;34mµç[2;37;0m:[1;31mÎŞË«[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;31m»ÙÌì[2;37;0m ÌìÁé:[35m±ê×¼[2;37;0m ¾ø´ú:[34mÏ¸Ëé[2;37;0m ÇÉÖÆ:[33mºÜ¸ß[2;37;0m 
°×Ê¯:[31m¾«ÖÂ[2;37;0m ×ÏÊ¯:[33mºÜ¸ß[2;37;0m ³¤Éú:[35m±ê×¼[2;37;0m ÍşÁ¦:[32m´Ö²Ú[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mºÍ°×»¨[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32m¹÷·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "helonghhh");
		set("ownername", "ºÍ°×»¨");
		set("value", 25000);
		set("armor_prop/intelligence",51);
		set("armor_prop/strength",40);
		set("armor_prop/karey",24);
		set("armor_prop/percao",26);
		set("armor_prop/dexerity",32);
		set("armor_prop/constitution",24);
    set("armor_prop/dodge", 60);
    set("armor_prop/parry", 40);
    set("armor_prop/attack", 24);


    set("armor_prop/armor", 797);
    set("armor_prop/defense", 24);
    
    set("armor_prop/neili", 24);
    set("armor_prop/qi", 51);
    set("armor_prop/jing", 56);
    set("armor_prop/jingli", 48);
    set("armor_prop/damage", 1326);

    set("wtypeA",4);
    set("wtypeB",2);
    set("wtypeC",2);
    set("wtypeD",8);
    set("wtypeE",10);
    set("wtypeF",14);
    set("wtypeG",14);
    set("wtypeH",12);
    set("wtypeI",1);
    set("wtypeJ",4);
    set("wtypeK",5);
    set("wtypeL",4);
    
    
                set("skill", ([
                        "name": "club",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 18);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";