#include <ansi.h> 
#include <armor.h>

inherit HEAD;

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
	      set_name("[1;31m¶¥Ìì[2;37;0m", ({ "baihu head", "head" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¶¥");
		set("long", @LONG
[1;37m°×»¢Ö®Í·¿ø[2;37;0mÕâÊÇÒ»¶¥ÓÉÎŞ±È¼áÓ²µÄ[1;33m½ğÌú[2;37;0m¼ÓÉÏ[1;33mÄ¾ÃŞ»¨[2;37;0mÖÆ³É£¬ÖØËÄ½ïÆßÁ½ÎåÇ®µÄ[1;37m°×»¢Ö®Í·¿ø[2;37;0m¡£
×ÛºÏÆÀ¼Û[37m¾øÊÀÎŞË«[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[36m²»Ğ¡[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[36mÄ¾[2;37;0m:[1;36mÍêÃÀ[2;37;0m [33mÍÁ[2;37;0m:[1;35m¾øÊÀ[2;37;0m [1;35m·ç[2;37;0m:[1;36mÍêÃÀ[2;37;0m 
[1;37mÀ×[2;37;0m:[1;32mÄ§Íõ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;31mÎŞË«[2;37;0m ÌìÁé:[32m´Ö²Ú[2;37;0m ÇÉÖÆ:[32m´Ö²Ú[2;37;0m 
°×Ê¯:[35m±ê×¼[2;37;0m ×ÏÊ¯:[34mÏ¸Ëé[2;37;0m ÖÜÌì:[34mÏ¸Ëé[2;37;0m ÍşÁ¦:[35m±ê×¼[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32m·ÉÏè[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32m¹÷·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "wslxs");
		set("ownername", "·ÉÏè");
		set("value", 16000);
		set("armor_prop/intelligence",35);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 51);
    set("armor_prop/parry", 20);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 81);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 20);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 51);

    set("wtypeA",0);
    set("wtypeB",7);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",11);
    set("wtypeF",7);
    set("wtypeG",9);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "club",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		


		set("material", "default");
    set("sharpness", 12);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";